
#include <stdlib.h>
#include "../header/saltpepper.h"
#include "../header/bitmap.h"




void saltpepper(Bitmap *bitmap, int radius)
{
  int width = bitmap->info_header->width;
  int height = bitmap->info_header->height;
  
  int noise_pixel = (int){(double)(width*height*3)*radius};
  
  byte *saltpepper_array = malloc(width * height * 3);

  for(int row = 0; row < height; row++)
  {
    for(int i =0; i <noise_pixel; i++ )
    {
      int r = rand() % width;
      int c = rand() % height;
      int pixel_b =0;
      int pixel_g =0;
      int pixel_r =0;

      int ch = rand() % 3;
      Pixel *pixel = get_pixel(bitmap,r,c);

      pixel_b = pixel->b;
      pixel_g = pixel->g;
      pixel_r = pixel->r;

      noise_pixel = (rand() % 2 ==1 ) ? 255: 0;
    
      set_pixel(saltpepper_array, width,row,0,noise_pixel, noise_pixel, noise_pixel);
    }
  }  
}
