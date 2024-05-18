#include "lib.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        printf("Usage: %s <input file path>\n", argv[0]);
        return 1;
    }

    const char* inputFile = argv[1];
    File files[100];
    int fileCount;

    readFileData(inputFile, files, &fileCount);
    printFileData(files, fileCount);

    File largeFiles[100];
    int largeFileCount;
    filterFilesBySize(files, fileCount, 50.0, largeFiles, &largeFileCount);
    printf("\nFiles larger than 50 KB:\n");
    printFileData(largeFiles, largeFileCount);

    File* secondFile = findSecondFileWithPermissions(files, fileCount);
    if (secondFile) {
        printf("\nSecond file with full permissions:\n");
        printf("Hidden: %d, Name: %s, Size: %.2lf KB, Permissions: %d%d%d, Format: %s\n",
               secondFile->hidden, secondFile->name, secondFile->size,
               secondFile->permissions.read, secondFile->permissions.write, secondFile->permissions.execute,
               secondFile->format);
    } else {
        printf("\nNo second file with full permissions found.\n");
    }

    ImageFile images[100];
    int imageCount = 0;
    for (int i = 0; i < fileCount; i++) {
        if (strcmp(files[i].format, "jpg") == 0 || strcmp(files[i].format, "png") == 0) {
            images[imageCount].base = files[i];
            // Assign some values to width, height, and dpi for demonstration
            images[imageCount].width = 1920;
            images[imageCount].height = 1080;
            images[imageCount].dpi = 300;
            imageCount++;
        }
    }

    ImageFile* smallestImage = findImageWithLeastPixels(images, imageCount);
    if (smallestImage) {
        printf("\nImage with the least pixels:\n");
        printf("Hidden: %d, Name: %s, Size: %.2lf KB, Permissions: %d%d%d, Format: %s\n",
               smallestImage->base.hidden, smallestImage->base.name, smallestImage->base.size,
               smallestImage->base.permissions.read, smallestImage->base.permissions.write, smallestImage->base.permissions.execute,
               smallestImage->base.format);
        printf("Resolution: %dx%d, DPI: %d\n", smallestImage->width, smallestImage->height, smallestImage->dpi);
    } else {
        printf("\nNo images found.\n");
    }

    return 0;
}