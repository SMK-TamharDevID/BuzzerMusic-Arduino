#define BUZZER_PIN 8  // Pin untuk buzzer

// Nada-nada dasar (frekuensi dalam Hz)
#define NOTE_C4  262  // Nada C4
#define NOTE_D4  294  // Nada D4
#define NOTE_E4  330  // Nada E4
#define NOTE_F4  349  // Nada F4
#define NOTE_G4  392  // Nada G4
#define NOTE_A4  440  // Nada A4
#define NOTE_B4  494  // Nada B4
#define NOTE_C5  523  // Nada C5 (satu oktaf lebih tinggi dari C4)

// Melodi lagu Twinkle Twinkle Little Star (Versi Lengkap)
int melody[] = {
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,    // Baris pertama lirik
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4,    // Baris kedua lirik
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,    // Baris ketiga lirik
  NOTE_G4, NOTE_G4, NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4,    // Baris keempat lirik
  NOTE_C4, NOTE_C4, NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4,    // Baris kelima lirik
  NOTE_F4, NOTE_F4, NOTE_E4, NOTE_E4, NOTE_D4, NOTE_D4, NOTE_C4     // Baris keenam lirik
};

// Durasi tiap nada (4 = seperempat, 8 = seperdelapan, dst.)
int noteDurations[] = {
  4, 4, 4, 4, 4, 4, 2,      // Durasi nada di baris pertama lirik
  4, 4, 4, 4, 4, 4, 2,      // Durasi nada di baris kedua lirik
  4, 4, 4, 4, 4, 4, 2,      // Durasi nada di baris ketiga lirik
  4, 4, 4, 4, 4, 4, 2,      // Durasi nada di baris keempat lirik
  4, 4, 4, 4, 4, 4, 2,      // Durasi nada di baris kelima lirik
  4, 4, 4, 4, 4, 4, 2       // Durasi nada di baris keenam lirik
};

void setup() {
  // Loop untuk memainkan lagu dan mengulangnya
  while (true) {
    for (int i = 0; i < sizeof(melody) / sizeof(melody[0]); i++) {
      int noteDuration = 1000 / noteDurations[i]; // Hitung durasi setiap nada dalam milidetik
      tone(BUZZER_PIN, melody[i], noteDuration);  // Mainkan nada dengan durasi tertentu
      delay(noteDuration * 1.3);                  // Jeda antar nada (1.3 kali durasi nada)
      noTone(BUZZER_PIN);                         // Matikan nada sebelum melanjutkan ke nada berikutnya
    }
  }
}

void loop() {
  // Tidak ada fungsi loop, musik akan diulang tanpa henti di setup
}
