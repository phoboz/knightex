#ifndef _RASTER_DRAW_H
#define _RASTER_DRAW_H

#define jsru(m, func)       asm("ldu %0\n\t" \
                                "jsr " #func "\n\t" : : "g" (m) : "d", "x", "u")

#define rasterDraw(data)	jsru(data, draw_raster_image)

#endif
