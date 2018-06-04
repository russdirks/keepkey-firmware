/*
 * This file is part of the KeepKey project.
 *
 * Copyright (C) 2015 KeepKey LLC
 *
 * This library is free software: you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this library.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "keepkey/board/resources.h"

#include "keepkey/board/keepkey_flash.h"
#include "keepkey/variant/variant.h"

#include <string.h>



static const uint8_t kk_logo_1_data[1189] = 
{
        0xfc, 0xb5, 0xf7, 0xeb, 0x58, 0x34, 0x00, 0x03, 0xff, 0xff, 0xdd, 0x34, 0x00, 0xff, 0xe2, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x05, 0x00, 0xfe, 0x33, 0xf7, 0x02, 0xff, 0x04, 0x00, 0xfd, 0x11, 0x8f, 0xe2, 0x03, 0xff, 0xfd, 0xdd, 0x79, 0x07, 0x05, 0x00, 0xfd, 0x11, 0x8f, 0xe2, 0x03, 0xff, 0xfd, 0xdd, 0x79, 0x07, 0x03, 0x00, 0xf4, 0xb5, 0xf7, 0xeb, 0x58, 0x11, 0x8f, 0xdd, 0xff, 0xeb, 0xb5, 0x79, 0x07, 0x02, 0x00, 0x03, 0xff, 0x04, 0x00, 0xfe, 0x1c, 0xeb, 0x03, 0xff, 0x03, 0x00, 0xfe, 0x1c, 0xdd, 0x07, 0xff, 0xfe, 0xb5, 0x07, 0x03, 0x00, 0xfe, 0x1c, 0xdd, 0x07, 0xff, 0xfe, 0xb5, 0x07, 0x02, 0x00, 0x03, 0xff, 0x02, 0xdd, 0x06, 0xff, 0xfd, 0xdd, 0x1c, 0x00, 0x03, 0xff, 0x03, 0x00, 0xfe, 0x11, 0xdd, 0x04, 0xff, 0x02, 0x00, 0xfe, 0x07, 0xcd, 0x03, 0xff, 0xfc, 0xb5, 0x8f, 0xa3, 0xeb, 0x02, 0xff, 0xff, 0x8f, 0x02, 0x00, 0xfe, 0x07, 0xcd, 0x03, 0xff, 0xfc, 0xb5, 0x8f, 0xa3, 0xeb, 0x02, 0xff, 0xff, 0x8f, 0x02, 0x00, 0xff, 0xe2, 0x0b, 0xff, 0xfe, 0xb5, 0x00, 0x03, 0xff, 0x02, 0x00, 0xfe, 0x07, 0xcd, 0x03, 0xff, 0xff, 0x79, 0x03, 0x00, 0xff, 0x58, 0x02, 0xff, 0xfe, 0xf7, 0x33, 0x03, 0x00, 0xfe, 0x1c, 0xeb, 0x02, 0xff, 0xfd, 0x11, 0x00, 0x58, 0x02, 0xff, 0xfe, 0xf7, 0x33, 0x03, 0x00, 0xfe, 0x1c, 0xeb, 0x02, 0xff, 0xff, 0x11, 0x02, 0x00, 0x03, 0xff, 0xfe, 0xa3, 0x33, 0x02, 0x07, 0xfe, 0x33, 0xdd, 0x02, 0xff, 0xfe, 0xf7, 0x00, 0x03, 0xff, 0xfd, 0x00, 0x07, 0xb5, 0x03, 0xff, 0xff, 0x79, 0x04, 0x00, 0xff, 0xa3, 0x02, 0xff, 0xff, 0x8f, 0x05, 0x00, 0xff, 0xa3, 0x02, 0xff, 0xfd, 0x58, 0x00, 0xa3, 0x02, 0xff, 0xff, 0x8f, 0x05, 0x00, 0xff, 0xa3, 0x02, 0xff, 0xff, 0x58, 0x02, 0x00, 0x03, 0xff, 0x05, 0x00, 0xff, 0x58, 0x03, 0xff, 0xff, 0x00, 0x08, 0xff, 0xff, 0x79, 0x05, 0x00, 0xff, 0xdd, 0x02, 0xff, 0xff, 0x33, 0x05, 0x00, 0xff, 0x79, 0x02, 0xff, 0xfd, 0x8f, 0x00, 0xdd, 0x02, 0xff, 0xff, 0x33, 0x05, 0x00, 0xff, 0x79, 0x02, 0xff, 0xff, 0x8f, 0x02, 0x00, 0x03, 0xff, 0x05, 0x00, 0xff, 0x1c, 0x03, 0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0x79, 0x06, 0x00, 0x0c, 0xff, 0xfe, 0xb5, 0x00, 0x0c, 0xff, 0xff, 0xb5, 0x02, 0x00, 0x03, 0xff, 0x05, 0x00, 0xff, 0x07, 0x03, 0xff, 0xff, 0x00, 0x07, 0xff, 0xff, 0x79, 0x06, 0x00, 0x0c, 0xff, 0xfe, 0xa3, 0x00, 0x0c, 0xff, 0xff, 0xa3, 0x02, 0x00, 0x03, 0xff, 0x05, 0x00, 0xff, 0x07, 0x03, 0xff, 0xff, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x8f, 0x03, 0xff, 0xff, 0x79, 0x05, 0x00, 0xfd, 0xe2, 0xff, 0xf7, 0x0b, 0x00, 0xfd, 0xe2, 0xff, 0xf7, 0x0c, 0x00, 0x03, 0xff, 0x05, 0x00, 0xff, 0x1c, 0x03, 0xff, 0xff, 0x00, 0x03, 0xff, 0xfd, 0x00, 0x07, 0xb5, 0x03, 0xff, 0xff, 0x79, 0x04, 0x00, 0xff, 0xb5, 0x02, 0xff, 0xff, 0x11, 0x0a, 0x00, 0xff, 0xb5, 0x02, 0xff, 0xff, 0x11, 0x0b, 0x00, 0x03, 0xff, 0x05, 0x00, 0xff, 0x58, 0x03, 0xff, 0xff, 0x00, 0x03, 0xff, 0x02, 0x00, 0xfe, 0x07, 0xcd, 0x03, 0xff, 0xff, 0x79, 0x03, 0x00, 0xff, 0x79, 0x02, 0xff, 0xff, 0x8f, 0x04, 0x00, 0xfc, 0x07, 0x58, 0x8f, 0x11, 0x02, 0x00, 0xff, 0x79, 0x02, 0xff, 0xff, 0x8f, 0x04, 0x00, 0xfc, 0x07, 0x58, 0x8f, 0x11, 0x03, 0x00, 0x03, 0xff, 0xfe, 0xa3, 0x33, 0x02, 0x07, 0xfe, 0x33, 0xdd, 0x02, 0xff, 0xfe, 0xf7, 0x00, 0x03, 0xff, 0x03, 0x00, 0xfe, 0x11, 0xdd, 0x04, 0xff, 0x02, 0x00, 0xfe, 0x07, 0xeb, 0x02, 0xff, 0xfb, 0xdd, 0xa3, 0x8f, 0xb5, 0xe2, 0x02, 0xff, 0xff, 0x8f, 0x02, 0x00, 0xfe, 0x07, 0xeb, 0x02, 0xff, 0xfb, 0xdd, 0xa3, 0x8f, 0xb5, 0xe2, 0x02, 0xff, 0xff, 0x8f, 0x03, 0x00, 0x0b, 0xff, 0xfe, 0xb5, 0x00, 0x03, 0xff, 0x04, 0x00, 0xfe, 0x1c, 0xeb, 0x03, 0xff, 0x03, 0x00, 0xfe, 0x33, 0xf7, 0x08, 0xff, 0xff, 0xa3, 0x03, 0x00, 0xfe, 0x33, 0xf7, 0x08, 0xff, 0xff, 0xa3, 0x03, 0x00, 0x03, 0xff, 0xff, 0xdd, 0x06, 0xff, 0xfd, 0xdd, 0x1c, 0x00, 0x03, 0xff, 0x05, 0x00, 0xfe, 0x33, 0xf7, 0x02, 0xff, 0x04, 0x00, 0xf7, 0x1c, 0xa3, 0xe2, 0xff, 0xf7, 0xe2, 0xb5, 0x8f, 0x33, 0x05, 0x00, 0xf7, 0x1c, 0xa3, 0xe2, 0xff, 0xf7, 0xe2, 0xb5, 0x8f, 0x33, 0x04, 0x00, 0x03, 0xff, 0xf8, 0x11, 0x8f, 0xdd, 0xff, 0xeb, 0xb5, 0x79, 0x07, 0x02, 0x00, 0x03, 0xff, 0x28, 0x00, 0x03, 0xff, 0x0a, 0x00, 0x03, 0xff, 0x28, 0x00, 0x03, 0xff, 0x0a, 0x00, 0x03, 0xff, 0x28, 0x00, 0x03, 0xff, 0x0a, 0x00, 0x03, 0xff, 0x28, 0x00, 0x03, 0xff, 0x0a, 0x00, 0x03, 0xff, 0x05, 0x00, 0xfe, 0x33, 0xf7, 0x02, 0xff, 0x04, 0x00, 0xfd, 0x11, 0x8f, 0xe2, 0x03, 0xff, 0xfd, 0xdd, 0x79, 0x07, 0x02, 0x00, 0x05, 0xff, 0x04, 0x00, 0x05, 0xff, 0x02, 0x00, 0x03, 0xff, 0x0a, 0x00, 0x03, 0xff, 0x04, 0x00, 0xfe, 0x1c, 0xeb, 0x03, 0xff, 0x03, 0x00, 0xfe, 0x1c, 0xdd, 0x07, 0xff, 0xfd, 0xb5, 0x07, 0x00, 0x05, 0xff, 0x04, 0x00, 0x05, 0xff, 0x02, 0x00, 0x03, 0xff, 0x0a, 0x00, 0x03, 0xff, 0x03, 0x00, 0xfe, 0x11, 0xdd, 0x04, 0xff, 0x02, 0x00, 0xfe, 0x07, 0xcd, 0x03, 0xff, 0xfc, 0xb5, 0x8f, 0xa3, 0xeb, 0x02, 0xff, 0xff, 0x8f, 0x03, 0x00, 0x03, 0xff, 0x06, 0x00, 0x03, 0xff, 0x02, 0x00, 0x03, 0xff, 0x0a, 0x00, 0x03, 0xff, 0x02, 0x00, 0xfe, 0x07, 0xcd, 0x03, 0xff, 0xff, 0x79, 0x03, 0x00, 0xff, 0x58, 0x02, 0xff, 0xfe, 0xf7, 0x33, 0x03, 0x00, 0xfe, 0x1c, 0xeb, 0x02, 0xff, 0xff, 0x11, 0x02, 0x00, 0x03, 0xff, 0x06, 0x00, 0x03, 0xff, 0x0f, 0x00, 0x03, 0xff, 0xfd, 0x00, 0x07, 0xb5, 0x03, 0xff, 0xff, 0x79, 0x04, 0x00, 0xff, 0xa3, 0x02, 0xff, 0xff, 0x8f, 0x05, 0x00, 0xff, 0xa3, 0x02, 0xff, 0xff, 0x58, 0x02, 0x00, 0x03, 0xff, 0x06, 0x00, 0x03, 0xff, 0x0f, 0x00, 0x08, 0xff, 0xff, 0x79, 0x05, 0x00, 0xff, 0xdd, 0x02, 0xff, 0xff, 0x33, 0x05, 0x00, 0xff, 0x79, 0x02, 0xff, 0xff, 0x8f, 0x02, 0x00, 0x03, 0xff, 0x06, 0x00, 0x03, 0xff, 0x0f, 0x00, 0x07, 0xff, 0xff, 0x79, 0x06, 0x00, 0x0c, 0xff, 0xff, 0xb5, 0x02, 0x00, 0x03, 0xff, 0x06, 0x00, 0x03, 0xff, 0x0f, 0x00, 0x07, 0xff, 0xff, 0x79, 0x06, 0x00, 0x0c, 0xff, 0xff, 0xa3, 0x02, 0x00, 0x03, 0xff, 0x06, 0x00, 0x03, 0xff, 0x0f, 0x00, 0x03, 0xff, 0xfe, 0x00, 0x8f, 0x03, 0xff, 0xff, 0x79, 0x05, 0x00, 0xfd, 0xe2, 0xff, 0xf7, 0x0c, 0x00, 0x03, 0xff, 0xff, 0x07, 0x05, 0x00, 0x03, 0xff, 0x0f, 0x00, 0x03, 0xff, 0xfd, 0x00, 0x07, 0xb5, 0x03, 0xff, 0xff, 0x79, 0x04, 0x00, 0xff, 0xb5, 0x02, 0xff, 0xff, 0x11, 0x0b, 0x00, 0xff, 0xeb, 0x02, 0xff, 0xff, 0x1c, 0x04, 0x00, 0xff, 0x11, 0x03, 0xff, 0x0f, 0x00, 0x03, 0xff, 0x02, 0x00, 0xfe, 0x07, 0xcd, 0x03, 0xff, 0xff, 0x79, 0x03, 0x00, 0xff, 0x79, 0x02, 0xff, 0xff, 0x8f, 0x04, 0x00, 0xfc, 0x07, 0x58, 0x8f, 0x11, 0x03, 0x00, 0xff, 0xb5, 0x02, 0xff, 0xff, 0x58, 0x03, 0x00, 0xfe, 0x07, 0xb5, 0x03, 0xff, 0x0f, 0x00, 0x03, 0xff, 0x03, 0x00, 0xfe, 0x11, 0xdd, 0x04, 0xff, 0x02, 0x00, 0xfe, 0x07, 0xeb, 0x02, 0xff, 0xfb, 0xdd, 0xa3, 0x8f, 0xb5, 0xe2, 0x02, 0xff, 0xff, 0x8f, 0x03, 0x00, 0xff, 0x79, 0x02, 0xff, 0xfb, 0xf7, 0xa3, 0x8f, 0xb5, 0xe2, 0x04, 0xff, 0x0f, 0x00, 0x03, 0xff, 0x04, 0x00, 0xfe, 0x1c, 0xeb, 0x03, 0xff, 0x03, 0x00, 0xfe, 0x33, 0xf7, 0x08, 0xff, 0xff, 0xa3, 0x03, 0x00, 0xfe, 0x07, 0xdd, 0x06, 0xff, 0xff, 0x8f, 0x03, 0xff, 0x0f, 0x00, 0x03, 0xff, 0x05, 0x00, 0xfe, 0x33, 0xf7, 0x02, 0xff, 0x04, 0x00, 0xf7, 0x1c, 0xa3, 0xe2, 0xff, 0xf7, 0xe2, 0xb5, 0x8f, 0x33, 0x05, 0x00, 0xf8, 0x11, 0xa3, 0xe2, 0xff, 0xeb, 0xb5, 0x58, 0x00, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x35, 0x00, 0x03, 0xff, 0x34, 0x00, 0xff, 0xe2, 0x03, 0xff, 0x34, 0x00, 0x03, 0xff, 0xff, 0xdd, 0x34, 0x00, 0xfc, 0xb5, 0xf7, 0xeb, 0x58, 0x7f, 0x00, 0x37, 0x00
};
static const VariantImage kk_logo_1_image = {56, 49, sizeof(kk_logo_1_data), kk_logo_1_data};


static const VariantAnimation kk_logo = {
    21, 
    {
        {100, 9, 25, 0, &kk_logo_1_image},
        {100, 9, 25, 5, &kk_logo_1_image},
        {100, 9, 25, 10, &kk_logo_1_image},
        {100, 9, 25, 15, &kk_logo_1_image},
        {100, 9, 25, 20, &kk_logo_1_image},
        {100, 9, 25, 25, &kk_logo_1_image},
        {100, 9, 25, 30, &kk_logo_1_image},
        {100, 9, 25, 35, &kk_logo_1_image},
        {100, 9, 25, 40, &kk_logo_1_image},
        {100, 9, 25, 45, &kk_logo_1_image},
        {100, 9, 25, 50, &kk_logo_1_image},
        {100, 9, 25, 55, &kk_logo_1_image},
        {100, 9, 25, 60, &kk_logo_1_image},
        {100, 9, 25, 65, &kk_logo_1_image},
        {100, 9, 25, 70, &kk_logo_1_image},
        {100, 9, 25, 75, &kk_logo_1_image},
        {100, 9, 25, 80, &kk_logo_1_image},
        {100, 9, 25, 85, &kk_logo_1_image},
        {100, 9, 25, 90, &kk_logo_1_image},
        {100, 9, 25, 95, &kk_logo_1_image},
        {100, 9, 25, 100, &kk_logo_1_image}
    }
};
static const VariantAnimation kk_logo_reversed = {
    21, 
    {
        {100, 9, 25, 100, &kk_logo_1_image},
        {100, 9, 25, 95, &kk_logo_1_image},
        {100, 9, 25, 90, &kk_logo_1_image},
        {100, 9, 25, 85, &kk_logo_1_image},
        {100, 9, 25, 80, &kk_logo_1_image},
        {100, 9, 25, 75, &kk_logo_1_image},
        {100, 9, 25, 70, &kk_logo_1_image},
        {100, 9, 25, 65, &kk_logo_1_image},
        {100, 9, 25, 60, &kk_logo_1_image},
        {100, 9, 25, 55, &kk_logo_1_image},
        {100, 9, 25, 50, &kk_logo_1_image},
        {100, 9, 25, 45, &kk_logo_1_image},
        {100, 9, 25, 40, &kk_logo_1_image},
        {100, 9, 25, 35, &kk_logo_1_image},
        {100, 9, 25, 30, &kk_logo_1_image},
        {100, 9, 25, 25, &kk_logo_1_image},
        {100, 9, 25, 20, &kk_logo_1_image},
        {100, 9, 25, 15, &kk_logo_1_image},
        {100, 9, 25, 10, &kk_logo_1_image},
        {100, 9, 25, 5, &kk_logo_1_image},
        {100, 9, 25, 0, &kk_logo_1_image}
    }
};


/*
static void salt_logo_16(uint8_t *data)
{
    // FIXME: we need to actually animate this!
    const uint8_t image_data[526] =
    {
        0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x63, 0x00, 0x08, 0xff, 0x23, 0x00, 0xff, 0xff, 0x20, 0x00, 0x03, 0xff, 0x1b, 0x00, 0x13, 0xff, 0x0f, 0x00, 0x0c, 0xff, 0x21, 0x00, 0xff, 0xff, 0x20, 0x00, 0x03, 0xff, 0x1b, 0x00, 0x13, 0xff, 0x0e, 0x00, 0x0f, 0xff, 0x1e, 0x00, 0x03, 0xff, 0x1f, 0x00, 0x03, 0xff, 0x1b, 0x00, 0x13, 0xff, 0x0d, 0x00, 0x05, 0xff, 0x06, 0x00, 0x06, 0xff, 0x1d, 0x00, 0x03, 0xff, 0x1f, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x14, 0x00, 0x04, 0xff, 0x0b, 0x00, 0x03, 0xff, 0x1c, 0x00, 0x05, 0xff, 0x1e, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x14, 0x00, 0x03, 0xff, 0x0d, 0x00, 0xff, 0xff, 0x1d, 0x00, 0x05, 0xff, 0x1e, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x14, 0x00, 0x03, 0xff, 0x2a, 0x00, 0x07, 0xff, 0x1d, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x14, 0x00, 0x03, 0xff, 0x2a, 0x00, 0x03, 0xff, 0xff, 0x00, 0x03, 0xff, 0x1d, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x14, 0x00, 0x04, 0xff, 0x28, 0x00, 0x04, 0xff, 0xff, 0x00, 0x04, 0xff, 0x1c, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x14, 0x00, 0x04, 0xff, 0x28, 0x00, 0x03, 0xff, 0x03, 0x00, 0x03, 0xff, 0x1c, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x15, 0x00, 0x07, 0xff, 0x23, 0x00, 0x04, 0xff, 0x03, 0x00, 0x04, 0xff, 0x1b, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x16, 0x00, 0x0a, 0xff, 0x1f, 0x00, 0x03, 0xff, 0x05, 0x00, 0x03, 0xff, 0x1b, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x17, 0x00, 0x0c, 0xff, 0x1b, 0x00, 0x04, 0xff, 0x05, 0x00, 0x04, 0xff, 0x1a, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x1a, 0x00, 0x0a, 0xff, 0x1a, 0x00, 0x03, 0xff, 0x07, 0x00, 0x03, 0xff, 0x1a, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x1e, 0x00, 0x07, 0xff, 0x18, 0x00, 0x04, 0xff, 0x07, 0x00, 0x04, 0xff, 0x19, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x21, 0x00, 0x05, 0xff, 0x17, 0x00, 0x03, 0xff, 0x09, 0x00, 0x03, 0xff, 0x19, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x22, 0x00, 0x04, 0xff, 0x16, 0x00, 0x04, 0xff, 0x09, 0x00, 0x04, 0xff, 0x18, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x23, 0x00, 0x04, 0xff, 0x15, 0x00, 0x03, 0xff, 0x0b, 0x00, 0x03, 0xff, 0x18, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x23, 0x00, 0x04, 0xff, 0x14, 0x00, 0x04, 0xff, 0x0b, 0x00, 0x04, 0xff, 0x17, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x23, 0x00, 0x04, 0xff, 0x14, 0x00, 0x03, 0xff, 0x0d, 0x00, 0x03, 0xff, 0x17, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x15, 0x00, 0xff, 0xff, 0x0d, 0x00, 0x04, 0xff, 0x13, 0x00, 0x04, 0xff, 0x0d, 0x00, 0x04, 0xff, 0x16, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x14, 0x00, 0x03, 0xff, 0x0b, 0x00, 0x04, 0xff, 0x14, 0x00, 0x03, 0xff, 0x0f, 0x00, 0x03, 0xff, 0x16, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x14, 0x00, 0x05, 0xff, 0x08, 0x00, 0x05, 0xff, 0x13, 0x00, 0x04, 0xff, 0x0f, 0x00, 0x04, 0xff, 0x15, 0x00, 0x03, 0xff, 0x23, 0x00, 0x03, 0xff, 0x15, 0x00, 0x10, 0xff, 0x14, 0x00, 0x17, 0xff, 0x15, 0x00, 0x0f, 0xff, 0x17, 0x00, 0x03, 0xff, 0x16, 0x00, 0x0e, 0xff, 0x14, 0x00, 0x19, 0xff, 0x14, 0x00, 0x0f, 0xff, 0x17, 0x00, 0x03, 0xff, 0x19, 0x00, 0x08, 0xff, 0x17, 0x00, 0x19, 0xff, 0x14, 0x00, 0x0f, 0xff, 0x17, 0x00, 0x03, 0xff, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x7f, 0x00, 0x4c, 0x00
    };
    memcpy(data, image_data, sizeof(image_data));
}
static const Image salt_logo_16_image = {(void *) &salt_logo_16, 142, 36};

static const AnimationFrame salt_logo_array[] =
{
    {&salt_logo_16_image, 20}
};

static const ImageAnimation salt_logo = { 16, salt_logo_array };
*/

typedef struct {
    const VariantAnimation *const forward;
    const VariantAnimation *const reverse;
    const uint16_t base_x;
} LogoParams;

static const LogoParams keepkey_params = { &kk_logo, &kk_logo_reversed, 100 };
// TODO: fix after add salt
static const LogoParams salt_params = { &kk_logo, &kk_logo, 60 };

static const LogoParams *logo_paramsInit(void) {
    const char *model = flash_getModel();
    if (!model)
        return &keepkey_params;

#define MODEL_KK(MODEL) \
    if (!strcmp(model, (MODEL))) \
        return &keepkey_params;

#define MODEL_SALT(MODEL) \
    if (!strcmp(model, (MODEL))) \
        return &salt_params;

#include "keepkey/board/models.def"

    // If all else fails, just brand it as if it were a KeepKey
    return &keepkey_params;
}

static const LogoParams *logo_params(void) {
    static const LogoParams *params;
    if (!params)
        params = logo_paramsInit();
    return params;
}

const VariantAnimation *get_logo_animation(void)
{
    return logo_params()->forward;
}

const VariantAnimation *get_logo_reversed_animation(void)
{
    return logo_params()->reverse;
}

uint16_t get_logo_base_x(void) {
    return logo_params()->base_x;
}

