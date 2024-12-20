#include <mlx.h>
#include <libft.h>
#include <stdio.h>
#include <unistd.h>
#define WIDTH 1920
#define HEIGHT 1080
#include <fcntl.h>
#include <stdint.h>

// Structure pour les en-têtes BMP
#pragma pack(push, 1)
typedef struct {
    uint16_t type;               // Type de fichier, doit être "BM"
    uint32_t size;               // Taille du fichier
    uint16_t reserved1;          // Réservé, doit être 0
    uint16_t reserved2;          // Réservé, doit être 0
    uint32_t offset;             // Offset pour les données d'image
} BMPHeader;

typedef struct {
    uint32_t size;               // Taille de l'en-tête (40 octets)
    int32_t width;               // Largeur de l'image
    int32_t height;              // Hauteur de l'image
    uint16_t planes;             // Nombre de plans (doit être 1)
    uint16_t bitCount;           // Profondeur de couleur (24 pour RGB)
    uint32_t compression;        // Compression (0 pour aucun)
    uint32_t sizeImage;          // Taille des données de l'image
    int32_t xPelsPerMeter;       // Résolution en pixels par mètre
    int32_t yPelsPerMeter;       // Résolution en pixels par mètre
    uint32_t clrUsed;            // Nombre de couleurs utilisées
    uint32_t clrImportant;       // Nombre de couleurs importantes
} BMPInfoHeader;

typedef	struct s_img
{
	void	*img_ptr;
	int		height;
	int		width;
	int		line_length;
	int		bit_per_pixel;
	int		endian;
	char	*addr;
}	t_img;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img	img;
	t_img	xpm;
}	t_var;



#pragma pack(pop)

void save_bmp_image(const char *filename, int width, int height, unsigned char *pixels) {
    int fd = open(filename, O_WRONLY | O_CREAT | O_TRUNC, 0644);
    if (fd < 0) {
        perror("open");
        return;
    }

    BMPHeader bmpHeader = {0};
    BMPInfoHeader bmpInfoHeader = {0};

    // Remplir les en-têtes BMP
    bmpHeader.type = 0x4D42; // "BM" en hexadécimal
    bmpHeader.offset = sizeof(BMPHeader) + sizeof(BMPInfoHeader); // Offset après les en-têtes
    bmpHeader.size = bmpHeader.offset + (width * height * 3); // Taille totale du fichier BMP

    bmpInfoHeader.size = sizeof(BMPInfoHeader);
    bmpInfoHeader.width = width;
    bmpInfoHeader.height = -height; // Hauteur négative pour que l'image soit correctement orientée (haut vers le bas)
    bmpInfoHeader.planes = 1;
    bmpInfoHeader.bitCount = 24; // 24 bits (8 bits pour chaque composant RGB)
    bmpInfoHeader.sizeImage = width * height * 3; // Taille des données d'image
    bmpInfoHeader.xPelsPerMeter = 0;
    bmpInfoHeader.yPelsPerMeter = 0;
    bmpInfoHeader.clrUsed = 0;
    bmpInfoHeader.clrImportant = 0;

    // Écrire l'en-tête BMP
    write(fd, &bmpHeader, sizeof(bmpHeader));
    write(fd, &bmpInfoHeader, sizeof(bmpInfoHeader));

    // Écrire les données de l'image
    for (int y = height - 1; y >= 0; y--) {
        for (int x = 0; x < width; x++) {
            unsigned char pixel[3];
            int i = (y * width + x) * 4; // Pixel dans les données de MinilibX (32 bits par pixel)

            // Conversion de ARGB à RGB
            pixel[0] = pixels[i + 2]; // R
            pixel[1] = pixels[i + 1]; // G
            pixel[2] = pixels[i];     // B

            // Écrire un pixel RGB
            write(fd, pixel, 3);
        }

        // Remplir l'espace de remplissage de chaque ligne pour que les lignes aient un multiple de 4 octets
        int padding = (4 - (width * 3) % 4) % 4;
        unsigned char paddingBytes[3] = {0, 0, 0};
        if (padding > 0) {
            write(fd, paddingBytes, padding);
        }
    }

    close(fd);
}
void	put_pixel_img(t_img	*img, int x, int y, unsigned int color)
{
	int	index;
	unsigned int *pixels;

	if (color == 0xFF000000)
		return ;
	if (x >= 0 && y >= 0 && x < img->width && y < img->height)
	{
		index = y * img->line_length + x * img->bit_per_pixel / 8;
		pixels = (unsigned int *)(img->addr + index);
		*pixels = (unsigned int)color;
	}
}

unsigned int	get_pixel_img(t_img *img, int x, int y)
{
	return (*(unsigned int *)(img->addr + y * img->line_length + x * img->bit_per_pixel / 8));
}


void	rescale_img(t_img *initial, t_img *final, t_var *var)
{
	int	x;
	int	y;
	int	src_x;
	int	src_y;
	double	scale_x;
	double	scale_y;
	int		color;

	(void)var;
	scale_x = (double)initial->width / final->width;
	scale_y = (double)initial->height / final->height;
	y = 0;
	src_y = 0;
	src_x = 0;
	color = 0;
	while (y < final->height)
	{
		x = 0;
		while (x < final->width)
		{
			src_x = (int)(x * scale_x);
			src_y = (int)(y * scale_y);
			color = *(int *)(initial->addr+ src_y * initial->line_length + src_x * initial->bit_per_pixel / 8);
			*(int *)(final->addr + y * final->line_length + x * final->bit_per_pixel / 8) = color;
			x++;
		}
		y++;
	}
}

int	main(int ac, char **av)
{
	t_var	data;
	int		size_x;
	int		size_y;
	char	*file;

	if (ac < 4)
		return (ft_putendl_fd("Usage: ./scale <WIDTH> <HEIGHT> <FILE.bmp>", 1), 1);
	size_y = ft_atoi(av[1]);
	size_x = ft_atoi(av[2]);
	file = av[3];
	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, WIDTH, HEIGHT, "SCALER");
	data.xpm.img_ptr = mlx_xpm_file_to_image(data.mlx, "image1.xpm", &data.xpm.width, &data.xpm.height);
	data.xpm.addr = mlx_get_data_addr(data.xpm.img_ptr, &data.xpm.bit_per_pixel,
			   &data.xpm.line_length, &data.xpm.endian);
	data.img.img_ptr = mlx_new_image(data.mlx, size_x, size_y);
	data.img.addr = mlx_get_data_addr(data.img.img_ptr, &data.img.bit_per_pixel,
			   &data.img.line_length, &data.img.endian);
	data.img.width = size_x;
	data.img.height = size_y;
	rescale_img(&data.xpm, &data.img, &data);
	 save_bmp_image(file, data.img.width, data.img.height, (unsigned char *)data.img.addr);
	mlx_put_image_to_window(data.mlx, data.win, data.img.img_ptr, 0, 0);
	return (0);
}
