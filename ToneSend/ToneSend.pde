import ddf.minim.*;
import ddf.minim.analysis.*;
import ddf.minim.effects.*;
import ddf.minim.signals.*;
import ddf.minim.spi.*;
import ddf.minim.ugens.*;
import processing.serial.*;

Serial myPort;
Minim minim;
AudioOutput out;
int recData = 0;
int prev = 0;
String[] notes = {
  "C4", "D4", "E4", "F4", "G4", "A4", "B4",
  "C5", "D5", "E5", "F5", "G5", "A5", "B5",
  "C6", "D6", "E6", "F6", "G6", "A6", "B6",
};

void setup() {   
  myPort = new Serial(this, "/dev/cu.usbmodem1411", 19200);
  minim = new Minim(this);
  out = minim.getLineOut(Minim.STEREO);
  size(400, 400);
  background(0);
}

void draw() {
  try {
    if (recData == prev) {
      out.playNote(0);
    } else if (recData != 0 && prev != recData) {
      //---           startTime, duration, note
      out.playNote(0, 2, notes[recData-1]);
      delay(250);
      out.clearSignals();
    }
    delay(250);
    println(recData);
  } 
  catch(Exception e) {
    println(e.getMessage());
  }
}

void serialEvent(Serial port) {
  if (port.available() > 0) {
    recData = port.read();
  }
}

void stop() {
  out.close();
  minim.stop();
  super.stop();
}