#include "hw10.h"
//modify the main() function
#ifdef TEST_MAINFUNC

int main(int argc, char **argv){
  // check the arguments
  if(argc != 3)
  {
    printf("Wrong arguments\n");
    return EXIT_FAILURE;
  }

  // open the BMP file
  BMPImage * image = BMP_Open(argv[1]);
  if(image == NULL)
  {
    return EXIT_FAILURE;
  }

  // convert to gray scale
	// check for error in converting to gray scale
  BMPImage * grayImage = ImgToGray(image);
  if(grayImage == NULL)
  {
    return EXIT_FAILURE;
  }

  // write the gray image to file
  if(BMP_Write(argv[2], grayImage) != 1)
  {
    BMP_Free(image);
    BMP_Free(grayImage);
    return EXIT_FAILURE;
  }

  // free all the images
  BMP_Free(image);
  BMP_Free(grayImage);

  return EXIT_SUCCESS;
}

#endif
