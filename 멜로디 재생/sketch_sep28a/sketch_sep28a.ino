#include "pitches.h"

int speakerPin = 8;

int melody[] = {
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_G4, NOTE_G4, NOTE_E4, NOTE_E4, NOTE_D4, 0,
  NOTE_G4, NOTE_G4, NOTE_A4, NOTE_A4, NOTE_G4, NOTE_G4, NOTE_E4, 0,
  NOTE_G4, NOTE_E4, NOTE_D4, NOTE_E4, NOTE_C4, 0
};

int noteDuration = 4;

void setup() {
}

void loop() {
  for (int thisNote = 0; thisNote < sizeof(melody) / sizeof(int); thisNote++) {
    int noteLength = 1000 / noteDuration;
    tone(speakerPin, melody[thisNote], noteLength);

    int pauseBetweenNotes = noteLength * 1.30;
    delay(pauseBetweenNotes);
    noTone(speakerPin);
  }
  while (true) {};
}
