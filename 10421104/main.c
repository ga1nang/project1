#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <math.h>

#define STB_IMAGE_IMPLEMENTATION
#include ".\headers\stb_image.h"

#define STB_IMAGE_WRITE_IMPLEMENTATION  
#include ".\headers\stb_image_write.h"


unsigned char sub(unsigned char *background, unsigned char *foreground, unsigned char *weather, int width, int height, int channel)
{

    for (int i = 0; i < height; ++i)
    {
        for (int j = 0; j < width; ++j)
        {
            int diff = 0;

            for (int k = 0; k < channel+1; k++)
            {
                diff += abs(foreground[i*width*channel+j*channel+k] - background[i*width*channel+j*channel+k]);
            }

            if (i < 350 && diff < 170)
            {
                for (int k = 0; k < channel; k++)
                {
                    foreground[i*width*channel+j*channel+k] = weather[i*width*channel+j*channel+k];
                }
            }

            if (i >= 350 && diff < 150)
            {
                for (int k = 0; k < channel; k++)
                {
                    foreground[i*width*channel+j*channel+k] = weather[i*width*channel+j*channel+k];
                }
            }
            

            // if (diff < 150){
            //     for (int k = 0; k < channel; k++)
            //     {
            //         foreground[i*width*channel+j*channel+k] = weather[i*width*channel+j*channel+k];
            //     }
            // }
        }  
    }
}

int main(){
    
    int width1, height1, channel1;
    char path_img[] = ".\\images\\background.jpg";

    unsigned char *image1 = stbi_load(path_img, &width1, &height1, &channel1, 0);
    if (image1 == NULL)
    {
        printf("\nError");
        exit(1);
    }
    printf("Width = %d\nHeight = %d\nChannel = %d\n", width1, height1, channel1);
    
    
    int width2, height2, channel2;
    char path_img2[] = ".\\images\\foreground.jpg";

    unsigned char *image2 = stbi_load(path_img2, &width2, &height2, &channel2, 0);
    if (image2 == NULL)
    {
        printf("\nError");
        exit(1);
    }
    printf("\nWidth = %d\nHeight = %d\nChannel = %d\n", width2, height2, channel2);
  
    
    int width3, height3, channel3;
    char path_img3[] = ".\\images\\weather_forecast-resized.jpg";

    unsigned char *image3 = stbi_load(path_img3, &width3, &height3, &channel3, 0);
    if (image3 == NULL)
    {
        printf("\nError");
        exit(1);
    }
    printf("\nWidth = %d\nHeight = %d\nChannel = %d\n", width3, height3, channel3);

    sub(image1,image2,image3,width1,height1,channel1);
    
    char save_path[] = ".\\images\\new_img.jpeg";
    stbi_write_png(save_path,width2,height2,channel2,image2,width2*channel2);

    int tmp = 0;
    
    return 0;
}