int tabvitesse[6]= {0,25,50,75,100}; // valeurs de la vitesse du moteur en pourcentage
int vitesse[5]={0,0,0,0,0}; // initialisation du tableau de valeurs des vitesses PWM {0...255}
int bp = 2;

// Définir les broches utilisées pour L293D
int int1Pin = 5;         // entrée 1 (IN1) du L293D relié au PIN 5 ARDUINO
int int3Pin = 4;        // entrée 3 (IN3) du L293D relié au PIN 4 ARDUINO
int int4Pin = 3;       // entrée 4 (IN4) du L293D relié au PIN 3 ARDUINO    
int enable2Pin = 11;  // enablz 2 (EN2) du L293D relié au PIN 11 ARDUINO

// Define variables for motor direction and speed
int dir = 0;  
int spd = 0;



void setup ()
{  Serial.begin(9600);   // ouvrir port série avec 9600bits/s 

  pinMode(int1Pin,OUTPUT); // pin5 défini comme Sortie
  pinMode(bp,INPUT);
  digitalWrite (bp, LOW);

  pinMode(int3Pin, OUTPUT); // pin4 défini comme Sortie
  pinMode(int4Pin, OUTPUT);  // pin3 défini comme Sortie
  pinMode(enable2Pin, OUTPUT); // pin11 défini comme Sortie
}


void loop () 
{
int val = digitalRead(bp);
if ( val == HIGH)
{ MoteurVitessePWM();    // appel de la fonction MoteurVitesse PWM ()
  delay (1000);          // délai de 1s 
}
  

int valeur = analogRead(A0);   //lire la valeur du potentiomètre
  spd = map(abs(valeur - 512), 0, 512, 0, 255); // Calculate motor speed, pot travel from midpoint
  if (valeur > 512) // Compare to potentiometer midpoint to get motor direction
    dir = 0;
  else
    dir = 1;
  driveMotor(); //Call function to drive motor at calculated speed and direction
}



void MoteurVitessePWM()
{
  for (int i=0; i<5;i++)
  {
    vitesse [i]= int (255*tabvitesse[i]/100);
    analogWrite(int1Pin,255-vitesse[i]);


Serial.print("valeur PWM Vitesse :");     // Affichage sur le moniteur série le texte "valeur PWM Vitesse" 
Serial.println (255-vitesse[i]);                 // Affichage sur le moniteur série de la valeur PWM
delay(50); 
}}


void driveMotor() 
{
  if (dir)
  {
    digitalWrite(int3Pin, HIGH);
    digitalWrite(int4Pin, LOW);
  }
  else
  {
    digitalWrite(int3Pin, LOW);
    digitalWrite(int4Pin, HIGH);
  }
  analogWrite(enable2Pin, spd);


Serial.print("valeur spd :");     // Affichage sur le moniteur série le texte "valeur spd" 
Serial.println (spd);                 // Affichage sur le moniteur série de la valeur PWM
delay(50); 

  
}



















  
