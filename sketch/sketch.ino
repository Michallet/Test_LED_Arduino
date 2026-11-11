#include <Arduino_RouterBridge.h>
#include <Arduino_LED_Matrix.h>

Arduino_LED_Matrix matrix;
uint8_t frame[104];  // 8 lignes x 13 colonnes

const char* E_GLYPH[8] = {
  "....XXXXX....",
  "....X........",
  "....X........",
  "....XXXX.....",
  "....X........",
  "....X........",
  "....XXXXX....",
  "............."
};
const char* D_GLYPH[8] = {
  "....XXXX.....",
  "....X...X....",
  "....X...X....",
  "....X...X....",
  "....X...X....",
  "....X...X....",
  "....XXXX.....",
  "............."
};
const char* N_GLYPH[8] = {
  "....X...X....",
  "....XX..X....",
  "....X.X.X....",
  "....X.X.X....",
  "....X..XX....",
  "....X...X....",
  "....X...X....",
  "............."
};

void draw_glyph(const char* const rows[8]) {
  for (int r = 0; r < 8; r++)
    for (int c = 0; c < 13; c++)
      frame[r * 13 + c] = (rows[r][c] == 'X') ? 1 : 0;
  matrix.draw(frame);
}

// 0 = E, 1 = D, 2 = N, autre = effacer
void show(int index) {
  switch (index) {
    case 0: draw_glyph(E_GLYPH); break;
    case 1: draw_glyph(D_GLYPH); break;
    case 2: draw_glyph(N_GLYPH); break;
    default:
      memset(frame, 0, sizeof(frame));
      matrix.draw(frame);
  }
}

void setup() {
  matrix.begin();
  matrix.setGrayscaleBits(1);
  Bridge.begin();
  Bridge.provide_safe("show", show);
  show(-1);
}

void loop() {
  delay(10);
}
