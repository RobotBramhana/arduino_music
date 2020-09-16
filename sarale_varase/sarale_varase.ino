/*
 * ------------------------------------------------------------
 * "THE COFFEEWARE LICENSE" (Revision 2):
 * Sudhanva S wrote this code. As long as you retain this 
 * notice, you can do whatever you want with this stuff. If we
 * meet someday, and you think this stuff is worth it, you can
 * buy me a coffee in return.
 * 
 * Also, you might consider following me on GitHub for any comments
 * and/or questions you might have and if you'd like you can send 
 * me a donation at any time to support my work, ask me how!
 * ------------------------------------------------------------
 * 
 * @package sarale_varase
 * @file sarale_varase.ino
 *
 * @mainpage Doxygen Arduino Music Project
 *
 * @section description Description
 * A sketch when compiled and flashed on to Arduino by connecting 
 * a buzzer as shown in the circuit diagram, plays  
 * sarale varase from Carnatic Music.
 *
 * @section note Note
 * The declarations can also be made in *.h file when you wish to reuse.
 * 
 * @section circuit Circuit
 * - Buzzer connected to PIN 9.
 *
 * @section author Author
 * - Created by Sudhanva S on 15/Sep/2020.
 * 
 * @author Sudhanva S
 */

/** @brief Note sa, one of the Saptha Swaras. Frequency at 261 Hz  */
#define  s     3830    
/** @brief Note ri, one of the Saptha Swaras. Frequency at 294 Hz  */
#define  r     3400    
/** @brief Note ga, one of the Saptha Swaras. Frequency at 329 Hz  */  
#define  g     3038    
/** @brief Note ma, one of the Saptha Swaras. Frequency at 349 Hz  */
#define  m     2864    
/** @brief Note pa, one of the Saptha Swaras. Frequency at 392 Hz  */
#define  p     2550    
/** @brief Note da, one of the Saptha Swaras. Frequency at 440 Hz  */
#define  d     2272    
/** @brief Note ni, one of the Saptha Swaras. Frequency at 493 Hz  */
#define  n     2028    
/** @brief Note sa, one of the Saptha Swaras. But, on the next pitch. Frequency at 523 Hz  */
#define  S     1912    
/** @brief Note sa, one of the Saptha Swaras. But, on the next pitch.  */ 
#define  R     1686    
/** @brief To reset notes. Named it Z for 0 Hz  */
#define  Z     0       

/** @brief The buzzer connected to PIN 9. */
int speakerOut = 9; 

/** @brief Sapthaswaras in ascending notes order. */
int sarigamapadanisa[] = {s,r,g,m,p,d,n,S};

/** @brief Sapthaswaras in descending notes order. */
int sanidapamagarisa[] = {S,n,d,p,m,g,r,s};

/** @brief PWM for sapthswaras. */
int tunes[]  = { 256 }; 

/** @brief Tempo setting for the song. Higher values slows down the song. */
long tempo = 3500;

/** @brief Pause setting */
int pause = 1000;
int count = 100; 

/** @brief Temporary variable with global scope. */
int tone_ = 0;

/** @brief Temporary variable with global scope. */
int tune = 0;
long duration  = 0;

/**
 * @brief Does initial setup of the controller. Declares PIN as output.
 * 
 */
void setup() 
{ 
  pinMode(speakerOut, OUTPUT);
}
/**
 * @brief Performs PWM for the buzzer.
 * 
 */
void compose_music() 
{
  long elapsed_time = 0;
  if (tone_ > 0) 
  { 
    while (elapsed_time < duration) 
    {      
      digitalWrite(speakerOut,HIGH);
      delayMicroseconds(tone_ / 2);
     
      digitalWrite(speakerOut, LOW);
      delayMicroseconds(tone_ / 2);
      
     elapsed_time += (tone_);
    } 
  }
  else 
  {
    for (int j = 0; j < count; j++) 
    {
      delayMicroseconds(duration);  
    }                                
  }                                 
}
/**
 * @brief Loops the song infinitely.
 * 
 */
void loop() 
{
  for (int i=0; i<sizeof(sarigamapadanisa)/2; i++) 
  {
    tone_ = sarigamapadanisa[i];
    tune = tunes[i];
    duration = tune * tempo; 
    compose_music(); 
    delayMicroseconds(pause);
  }
  for (int i=0; i<sizeof(sanidapamagarisa)/2; i++) 
    {
    tone_ = sanidapamagarisa[i];
    tune = tunes[i];
    duration = tune * tempo; 
    compose_music(); 
    delayMicroseconds(pause);
  }
}
