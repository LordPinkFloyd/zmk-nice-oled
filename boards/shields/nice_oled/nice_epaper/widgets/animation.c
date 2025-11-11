#include "animation.h"
#include "screen_peripheral.h"
#include <stdlib.h>
#include <zephyr/kernel.h>

LV_IMG_DECLARE(crystal_01);
LV_IMG_DECLARE(crystal_02);
LV_IMG_DECLARE(crystal_03);
LV_IMG_DECLARE(crystal_04);
LV_IMG_DECLARE(crystal_05);
LV_IMG_DECLARE(crystal_06);
LV_IMG_DECLARE(crystal_07);
LV_IMG_DECLARE(crystal_08);
LV_IMG_DECLARE(crystal_09);
LV_IMG_DECLARE(crystal_10);
LV_IMG_DECLARE(crystal_11);
LV_IMG_DECLARE(crystal_12);
LV_IMG_DECLARE(crystal_13);
LV_IMG_DECLARE(crystal_14);
LV_IMG_DECLARE(crystal_15);
LV_IMG_DECLARE(crystal_16);

const lv_img_dsc_t *anim_imgs[] = {
    &crystal_01, &crystal_02, &crystal_03, &crystal_04, &crystal_05, &crystal_06,
    &crystal_07, &crystal_08, &crystal_09, &crystal_10, &crystal_11, &crystal_12,
    &crystal_13, &crystal_14, &crystal_15, &crystal_16,
};

LV_IMG_DECLARE(pokemon01);
LV_IMG_DECLARE(pokemon02);
LV_IMG_DECLARE(pokemon03);
LV_IMG_DECLARE(pokemon04);
LV_IMG_DECLARE(pokemon05);
LV_IMG_DECLARE(pokemon06);
LV_IMG_DECLARE(pokemon07);
LV_IMG_DECLARE(pokemon08);
LV_IMG_DECLARE(pokemon09);
LV_IMG_DECLARE(pokemon10);
LV_IMG_DECLARE(pokemon11);
LV_IMG_DECLARE(pokemon12);
LV_IMG_DECLARE(pokemon13);
LV_IMG_DECLARE(pokemon14);
LV_IMG_DECLARE(pokemon15);
LV_IMG_DECLARE(pokemon16);
LV_IMG_DECLARE(pokemon17);
LV_IMG_DECLARE(pokemon18);
LV_IMG_DECLARE(pokemon19);
LV_IMG_DECLARE(pokemon20);

const lv_img_dsc_t *pokemon_imgs[] = {
    &pokemon01, &pokemon02, &pokemon03, &pokemon04, &pokemon05, &pokemon06, &pokemon07,
    &pokemon08, &pokemon09, &pokemon10, &pokemon11, &pokemon12, &pokemon13, &pokemon14,
    &pokemon15, &pokemon16, &pokemon17, &pokemon18, &pokemon19, &pokemon20,
};

void draw_animation(lv_obj_t *canvas, struct zmk_widget_screen *widget) {
#if IS_ENABLED(CONFIG_NICE_OLED_GEM_ANIMATION)
    lv_obj_t *art = lv_animimg_create(widget->obj);
    lv_obj_center(art);

    lv_animimg_set_src(art, (const void **)pokemon_imgs, 20);
    lv_animimg_set_duration(art, 1260);
    lv_animimg_set_repeat_count(art, LV_ANIM_REPEAT_INFINITE);
    lv_animimg_start(art);
#else
    lv_obj_t *art = lv_img_create(widget->obj);

    int length = sizeof(anim_imgs) / sizeof(anim_imgs[0]);
    srand(k_uptime_get_32());
    int random_index = rand() % length;

    lv_img_set_src(art, anim_imgs[random_index]);
#endif

    lv_obj_align(art, LV_ALIGN_TOP_LEFT, -22, 0);
}
