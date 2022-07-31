#include "bmpimage.h"
// Modify all functions in this file



#ifdef TEST_HEADERVALID

/* check whether a header is valid or not
 * assume that header has been read from fptr
 * the position of the indicator of fptr is not certain
 * could be at the beginning of the file, end of the file or
 * anywhere in the file
 * note that the check is only for this assignment
 * in general, the format is more complicated and requires more checks
 */

int Is_BMPHeader_Valid(BMPHeader* header, FILE *fptr) {

  fseek(fptr, 0, SEEK_SET);

	// Make sure this is a BMP file -  magic number
  if(header -> type != 0x4D42)
  {
    //printf("Incorrect magic number\n");
    return EXIT_FAILURE;
  }
  
	// skip the two unused reserved fields
  
	// check the offset from beginning of file to image data
	// essentially the size of the BMP header
	// BMP_HEADER_SIZE for this exercise/assignment
	// printf("header->offset %d\n",header->offset );  
  if(header -> offset != BMP_HEADER_SIZE)
  {
    //printf("Incorrect offset\n");
    return EXIT_FAILURE;
  }

  // check the DIB header size == DIB_HEADER_SIZE
  if(header -> DIB_header_size != DIB_HEADER_SIZE)
  {
    //printf("Incorrect DIB header size\n");
    return EXIT_FAILURE;
  }
	// Make sure there is only one image plane
  if(header -> planes != 1)
  {
    //printf("Incorrent number of planes\n");
    return EXIT_FAILURE;
  }

	// Make sure there is no compression
  if(header -> compression != 0)
  {
    //printf("Incorrect compression\n");
    return EXIT_FAILURE;
  }

	// skip the test for xresolution, yresolution
	
	// ncolours and importantcolours should be 0
  if(header -> ncolours != 0 || header -> importantcolours != 0)
  {
    //printf("Incorrect colours\n");
    return EXIT_FAILURE;
  }
	// Make sure we are getting 24 bits per pixel
  if(header -> bits != 24)
  {
    //printf("Incorrect bits\n");
    return EXIT_FAILURE;
  }
	// only for this assignment
	// extra check for file size, image size
	// based on bits, width, and height
  int calcImageSize, calcFileSize; //the calculated image size and file size
  calcImageSize = (header->bits * header->width * header->height) / 8;
  if(calcImageSize != header -> imagesize)
  {
    //printf("Incorrect image size\n");
    return EXIT_FAILURE;
  }
  
  calcFileSize = calcImageSize + BMP_HEADER_SIZE;
  if(calcFileSize != header -> size)
  {
    //printf("Incorrect file size\n");
    return EXIT_FAILURE;
  }
		
	// check out the link: https://en.wikipedia.org/wiki/BMP_file_format#Pixel_storage
  return TRUE;
}

#endif



#ifdef TEST_BMPOPENFILE
/* The input argument is the source file pointer.
 * The function returns an address to a dynamically allocated BMPImage
 * only if the file contains a valid image file
 * Otherwise, return NULL
 * If the function cannot get the necessary memory to store the image,
 * also return NULL
 * Any error messages should be printed to stderr
 */


BMPImage *BMP_Open(const char *filename) {
  //open file
  //read file
  FILE *fptr = fopen(filename, "r");
  if(fptr == NULL)
  {
    printf("Error opening BMP file\n");
    return NULL;
  }

	//Allocate memory for BMPImage*;
  BMPImage * bmpImage = (BMPImage *)malloc(sizeof(BMPImage));

	//check for memory allocation errors
  if(bmpImage == NULL)
  {
    printf("Error opening BMP file\n");
    fclose(fptr);
    return NULL;
  }
	
	//Read the first 54 bytes of the source into the header
  int read_size = fread(&(bmpImage->header), sizeof(BMPHeader), 1, fptr);
  if(read_size != 1)
  {
    printf("Error opening BMP file\n");
    fclose(fptr);
    BMP_Free(bmpImage);
    return NULL;
  }
	
	//check if the header is valid
  if(Is_BMPHeader_Valid(&(bmpImage->header), fptr) != TRUE)
  {
    printf("Error opening BMP file\n");
    fclose(fptr);
    BMP_Free(bmpImage);
    return NULL;
  }

	// Allocate memory for image data
	//(bmpImage->data = (unsigned char *)malloc(sizeof(unsigned char)*((int)((bmpImage->header).imagesize))))
  bmpImage -> data = (unsigned char *)malloc(sizeof(unsigned char) * ((int)((bmpImage->header).imagesize)));

	//check error
  if(bmpImage -> data == NULL)
  {
    printf("Error opening BMP file\n");
    fclose(fptr);
    BMP_Free(bmpImage);
    return NULL;
  }

  fseek(fptr, BMP_HEADER_SIZE, SEEK_SET);

	// read in the image data
  read_size = fread(bmpImage->data, sizeof(char), (bmpImage->header).imagesize, fptr);
  	//check for error while reading
  if(read_size != (bmpImage->header).imagesize)
  {
    printf("Error opening BMP file\n");
    fclose(fptr);
    BMP_Free(bmpImage);
    return NULL;
  }

  /*char onebyte;
  if(fread(&onebyte, sizeof(char), 1, fptr) != 0)
  {
    //One more byte was able to be read which means we didn't reach the end of the file; it still has data that wasn't read
    printf("File not fully read\n");
    fclose(fptr);
    BMP_Free(bmpImage);
    return NULL;
  }*/

  fclose(fptr);
  //Both malloc's freed in BMP_Free function
  return bmpImage;
}
#endif


#ifdef TEST_BMPWRITEFUNC
/* The input arguments are the destination file , BMPImage *image.
 * The function write the header and image data into the destination file.
 */
int BMP_Write(const char * outfile, BMPImage* image)
{
	//open file and check for error
  FILE * fptr = fopen(outfile, "w");
  if(fptr == NULL)
  {
    printf("Fopen failed\n");
    BMP_Free(image);
    return EXIT_FAILURE;
  }

	//check error for writing
	
	// write and check for image data:(fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr) != (image->header).imagesize)
  int write_size = fwrite(&(image->header), sizeof(unsigned char), BMP_HEADER_SIZE, fptr);
  if(write_size != BMP_HEADER_SIZE)
  {
    printf("Fwrite failed\n");
    fclose(fptr);
    BMP_Free(image);
    return EXIT_FAILURE;
  }

  write_size = fwrite(image->data, sizeof(unsigned char), (image->header).imagesize, fptr);
  if(write_size != (image->header).imagesize)
  {
    printf("Fwrite failed\n");
    fclose(fptr);
    BMP_Free(image);
    return EXIT_FAILURE;
  } 
	
  fclose(fptr);
  return TRUE;
}

#endif
/* The input argument is the BMPImage pointer. The function frees memory of
 * the BMPImage.
 */
#ifdef TEST_BMPFREEFUNC
void BMP_Free(BMPImage* image) {
	//free image if image is true
  if(image != NULL)
  {
    if(image -> data != NULL)
    {
      free(image->data);
    }
    free(image);
  }
}

#endif

