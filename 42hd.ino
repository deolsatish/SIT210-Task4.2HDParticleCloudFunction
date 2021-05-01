int redled = D3;
int greenled = D4;
int blueled = D5;
bool ledredstatus = false;
bool ledgreenstatus = false;
bool leddluestatus = false;
int ledOnDelay = 150;


SYSTEM_THREAD(ENABLED);

void setup() {

  pinMode(redled, OUTPUT);
  pinMode(greenled, OUTPUT);
  pinMode(blueled, OUTPUT);

}

int ledToggle(String input) 
{
    if (input == "red") 
    {
        if (!ledredstatus)
        {
            digitalWrite(redled, HIGH);
            ledredstatus = true;
            
        }
        else 
        {
            digitalWrite(redled, LOW);
            ledredstatus = false;
        }
        Particle.publish("led Color","red",PRIVATE);
        return 1;
    }
    else if (input == "green")
    {
        if (!ledgreenstatus)
        {
            digitalWrite(greenled, HIGH); 
            ledgreenstatus = true;
        }
        else 
        {
            digitalWrite(greenled, LOW);
            ledgreenstatus = false;
        }
        
        Particle.publish("led Color","green",PRIVATE);
        return 2;
    } 
    else if (input == "blue")
    {
        if (!leddluestatus)
        {
            digitalWrite(blueled, HIGH); 
            leddluestatus = true;
        }
        else 
        {
            digitalWrite(blueled, LOW);
            leddluestatus = false;
        }
        
        Particle.publish("led Color","blue",PRIVATE);
        return 3;
    }
}


void loop() {
    
    Particle.function("toggle", ledToggle);
    
    
}