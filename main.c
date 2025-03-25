#include "c_img.h"
#include "seamcarving.h"
#include <stdio.h>
#include <stdlib.h>

int main() {
    printf("start\n");
    /*
    struct rgb_img *grad;
  
    struct rgb_img *im;
    read_in_img(&im, "3x4.bin");

    calc_energy(im,  &grad);
    
    print_grad(grad);

    
    struct rgb_img *im2;
    struct rgb_im *grad2;
    double *best;
    int w = 6;
    int h = 5;
    read_in_img(&im2, "6x5.bin");
    calc_energy(im2, &grad2);
    print_grad(grad2);
    dynamic_seam(grad2, &best);
    for(int i=0;i<h;i++){
        for(int j=0; j<w;j++){
            printf("%f\t",best[w*i+j]);
        }
        printf("\n");
    }
    */
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "HJoceanSmall.bin");
    
    for(int i = 0; i < 100; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);

        char filename[200];
        sprintf(filename, "img%d.bin", i);
        write_img(cur_im, filename);


        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
    }
    destroy_image(im);
    return 0;
}