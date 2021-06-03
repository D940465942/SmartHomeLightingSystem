/* 
    Pins Info of Electronic Components
    These pin and parameters could be configured by users
*/
bool overallSwitch = false;                 // overall and scene control switch
const int checkingBreak = 1000;             // The check break between each iteration in the loop

// Bedroom Scene
const int bedroomLED_1 = 1;                 // LEDs
const int bedroomLED_2 = 2;
const int bedroomLED_3 = 3;
const int bedroomHumanDetection = 7;        // The human detection sensor
const int bedroomInfraredReceiver = 8;      // The infrared receiver sensor
const int bedroomLightIntensity = 9;        // The light intensity sensor
const int bedroomDuration = 10000;          // The time for lighing be on after people live 
int currentBedroomDuration = 0;             // record the current duration that human has left
bool bedroomSwitch = false;                 // switch of each scene

// Balcony Scene
const int balconyLED_1 = 1;
const int balconyHumanDetection = 7;        // The human detection sensor
const int balconyInfraredReceiver = 8;      // The infrared receiver sensor
const int balconyLightIntensity = 9;        // The light intensity sensor
const int balconyDuration = 10000;          // The time for lighing be on after people live
int currentBalconyDuration = 0;             // record the current duration that human has left
bool balconySwitch = false;                 // switch of each scene

// Living Room Scene
const int livingRoomLED_1 = 1;              // LEDs
const int livingRoomLED_2 = 2;
const int livingRoomLED_3 = 3;
const int livingRoomLED_4 = 4;
const int livingRoomLED_5 = 5;
const int livingRoomLED_6 = 6;
const int livingRoomHumanDetection = 7;     // The human detection sensor
const int livingRoomInfraredReceiver = 8;   // The infrared receiver sensor
const int livingoomDuration = 10000;        // The time for lighing be on after people live
int currentLivingoomDuration = 0;           // record the current duration that human has left
bool livingRoomSwitch = false;              // switch of each scene

// Dining Room Scene
const int diningRoomLED_1 = 1;              // LEDs
const int diningRoomLED_2 = 2;
const int diningRoomLED_3 = 3;
const int diningHumanDetection = 7;         // The human detection sensor
const int diningInfraredReceiver = 8;       // The infrared receiver sensor
const int diningDuration = 10000;           // The time for lighing be on after people live
int currentDiningDuration = 0;              // record the current duration that human has left
bool diningRoomSwitch = false;              // switch of each scene

// Bathroom Scene
const int bathroomLED_1 = 1;                // LEDs
const int bathroonHumanDetection = 7;       // The human detection sensor
const int bathroomInfraredReceiver = 8;     // The infrared receiver sensor
const int bathroomDuration = 10000;         // The time for lighing be on after people live
int currentBathroomDuration = 0;            // record the current duration that human has left
bool bathroomSwitch = false;                // switch of each scene

// Kitchen Scene
const int kitchenLED_1 = 1;                 // LEDs
const int kitchenHumanDetection = 7;        // The human detection sensor
const int kitchenInfraredReceiver = 8;      // The infrared receiver sensor
const int kitchenDuration = 10000;          // The time for lighing be on after people live
int currentKitchenDuration = 0;             // record the current duration that human has left
bool kitchenSwitch = false;                 // switch of each scene

// Corridor Scene
const int corridorLED_1 = 1;                // LEDs
const int corridorLED_2 = 2;
const int corridorHumanDetection = 7;       // The human detection sensor
const int corridorLightIntensity = 9;       // The light intensity sensor
const int corridorVoiceDetection = 10;      // The voice detection sensor
const int corridorDuration = 10000;         // The time for lighing be on after people live
int currentCorridorDuration = 0;            // record the current duration that human has left


void setup()
{
    // Bedroom Scene
	pinMode(bedroomLED_1, OUTPUT);
	pinMode(bedroomLED_2, OUTPUT);
	pinMode(bedroomLED_3, OUTPUT);
	pinMode(bedroomHumanDetection, INPUT);
	pinMode(bedroomInfraredReceiver, INPUT);
	pinMode(bedroomLightIntensity, INPUT);
	
	// Balcony Scene
	pinMode(balconyLED_1, OUTPUT);
	pinMode(balconyHumanDetection, INPUT);
	pinMode(balconyInfraredReceiver, INPUT);
	pinMode(balconyLightIntensity, INPUT);
	
	// Living Room Scene
	pinMode(livingRoomLED_1, OUTPUT);
	pinMode(livingRoomLED_2, OUTPUT);
	pinMode(livingRoomLED_3, OUTPUT);
	pinMode(livingRoomLED_4, OUTPUT);
	pinMode(livingRoomLED_5, OUTPUT);
	pinMode(livingRoomLED_6, OUTPUT);
	pinMode(balconyHumanDetection, INPUT);
	pinMode(balconyInfraredReceiver, INPUT);
	
	// Dining Room Scene
	pinMode(diningRoomLED_1, OUTPUT);
	pinMode(diningRoomLED_2, OUTPUT);
	pinMode(diningRoomLED_3, OUTPUT);
	pinMode(diningHumanDetection, INPUT);
	pinMode(diningInfraredReceiver, INPUT);

    // Bathroom Scene
	pinMode(bathroomLED_1, OUTPUT);
	pinMode(bathroonHumanDetection, INPUT);
	pinMode(bathroomInfraredReceiver, INPUT);
	
	// Kitchen Scene
	pinMode(kitchenLED_1, OUTPUT);
	pinMode(kitchenHumanDetection, INPUT);
	pinMode(kitchenInfraredReceiver, INPUT);
	
	// Corridor Scene
	pinMode(corridorLED_1, OUTPUT);
	pinMode(corridorLED_2, OUTPUT);
	pinMode(corridorHumanDetection, INPUT);
	pinMode(corridorLightIntensity, INPUT);
	pinMode(corridorVoiceDetection, INPUT);
	
	Serial.begin(9600);
}

// turn on or off the overall switch by the command
// the other scene can only be turned on after overallSwitch turn on
void overall_control(bool command)
{
    overallSwitch = command;
}

// detect human
bool human_detection(int pin)
{
    int status = digitalRead(pin);
    
    if(status == HIGH)
    {
        return true;
    }
    return false;
}

// receive infrared to turn off each scene
bool receive_infrared(int pin)
{
    int status = digitalRead(pin);
    
    if(status == HIGH)
    {
        return true;
    }
    return false;
}

// detect the intensity of lights to adjust the birghtness of LEDs
float light_intensity()
{
    
}

// detect voice to turn on the light
bool voice_detection(int pin)
{
    int status = digitalRead(pin);
    
    if(status == HIGH)
    {
        return true;
    }

    return false;
}

void bedroom_scene()
{
    if(!overallSwitch)
    {
        digitalWrite(bedroomLED_1, LOW);
        digitalWrite(bedroomLED_2, LOW);
        digitalWrite(bedroomLED_3, LOW);
        return;
    }
    
    if(receive_infrared(bedroomInfraredReceiver))
    {
        bedroomSwitch = bedroomSwitch ? false : true;
    }
    
    if(overallSwitch && bedroomSwitch)
    {
        if(human_detection(bedroomHumanDetection))
        {
            currentBedroomDuration = 0;
            digitalWrite(bedroomLED_1, HIGH);
            digitalWrite(bedroomLED_2, HIGH);
            digitalWrite(bedroomLED_3, HIGH);
        }
        else
        {
            currentBedroomDuration += checkingBreak;
            if(currentBedroomDuration >= bedroomDuration)
            {
                digitalWrite(bedroomLED_1, LOW);
                digitalWrite(bedroomLED_2, LOW);
                digitalWrite(bedroomLED_3, LOW);
            }
        }
    }
}

void balcony_scene()
{
    if(!overallSwitch)
    {
        digitalWrite(balconyLED_1, LOW);
        return;
    }
    
    if(receive_infrared(balconyInfraredReceiver))
    {
        balconySwitch = balconySwitch ? false : true;
    }
    
    if(overallSwitch && balconySwitch)
    {
        if(human_detection(balconyHumanDetection))
        {
            currentBalconyDuration = 0;
            digitalWrite(balconyLED_1, HIGH);
        }
        else
        {
            currentBalconyDuration += checkingBreak;
            if(currentBalconyDuration >= balconyDuration)
            {
                digitalWrite(balconyLED_1, LOW);
            }
        }
    }    
}

void living_room_scene()
{
    if(!overallSwitch)
    {
        digitalWrite(livingRoomLED_1, LOW);
        digitalWrite(livingRoomLED_2, LOW);
        digitalWrite(livingRoomLED_3, LOW);
        digitalWrite(livingRoomLED_4, LOW);
        digitalWrite(livingRoomLED_5, LOW);
        digitalWrite(livingRoomLED_6, LOW);
        return;
    }
    
    if(receive_infrared(livingRoomInfraredReceiver))
    {
        livingRoomSwitch = livingRoomSwitch ? false : true;
    }

    if(overallSwitch && livingRoomSwitch)
    {
        if(human_detection(livingRoomHumanDetection))
        {
            currentLivingoomDuration = 0;
            digitalWrite(livingRoomLED_1, HIGH);
            digitalWrite(livingRoomLED_2, HIGH);
            digitalWrite(livingRoomLED_3, HIGH);
            digitalWrite(livingRoomLED_4, HIGH);
            digitalWrite(livingRoomLED_5, HIGH);
            digitalWrite(livingRoomLED_6, HIGH);
        }
        else
        {
            currentLivingoomDuration += checkingBreak;
            if(currentLivingoomDuration >= livingoomDuration)
            {
                digitalWrite(livingRoomLED_1, LOW);
                digitalWrite(livingRoomLED_2, LOW);
                digitalWrite(livingRoomLED_3, LOW);
                digitalWrite(livingRoomLED_4, LOW);
                digitalWrite(livingRoomLED_5, LOW);
                digitalWrite(livingRoomLED_6, LOW);
            }
        }
    }
}

void dining_room_scene()
{
    if(!overallSwitch)
    {
        digitalWrite(diningRoomLED_1, LOW);
        digitalWrite(diningRoomLED_2, LOW);
        digitalWrite(diningRoomLED_3, LOW);
        return;
    }
    
    if(receive_infrared(diningInfraredReceiver))
    {
        diningRoomSwitch = diningRoomSwitch ? false : true;
    }
    
    if(overallSwitch && diningRoomSwitch)
    {
        if(human_detection(diningHumanDetection))
        {
            currentDiningDuration = 0;
            digitalWrite(diningRoomLED_1, HIGH);
            digitalWrite(diningRoomLED_2, HIGH);
            digitalWrite(diningRoomLED_3, HIGH);
        }
        else
        {
            currentDiningDuration += checkingBreak;
            if(currentDiningDuration >= diningDuration)
            {
                digitalWrite(diningRoomLED_1, LOW);
                digitalWrite(diningRoomLED_2, LOW);
                digitalWrite(diningRoomLED_3, LOW);
            }
        }
    }    
}

void bathroom_scene()
{
    if(!overallSwitch)
    {
        digitalWrite(bathroomLED_1, LOW);
        return;
    }

    if(receive_infrared(bathroomInfraredReceiver))
    {
        bathroomSwitch = bathroomSwitch ? false : true;
    }

    if(overallSwitch && bathroomSwitch)
    {
        if(human_detection(bathroonHumanDetection))
        {
            currentBathroomDuration = 0;
            digitalWrite(bathroomLED_1, HIGH);
        }
        else
        {
            currentBathroomDuration += checkingBreak;
            if(currentBathroomDuration >= bathroomDuration)
            {
                digitalWrite(bathroomLED_1, LOW);
            }
        }
    }
}

void kitchen_scene()
{
    if(!overallSwitch)
    {
        digitalWrite(kitchenLED_1, LOW);
        return;
    }
    
    if(receive_infrared(kitchenInfraredReceiver))
    {
        kitchenSwitch = kitchenSwitch ? false : true;
    }

    if(overallSwitch && kitchenSwitch)
    {
        if(human_detection(kitchenHumanDetection))
        {
            currentKitchenDuration = 0;
            digitalWrite(kitchenLED_1, HIGH);
        }
        else
        {
            currentKitchenDuration += checkingBreak;
            if(currentKitchenDuration >= kitchenDuration)
            {
                digitalWrite(kitchenLED_1, LOW);
            }
        }
    }    
}

void corridor_scene()
{
    if(human_detection(corridorHumanDetection) && voice_detection(corridorVoiceDetection))
    {
        digitalWrite(corridorLED_1, HIGH);
        digitalWrite(corridorLED_2, HIGH);
        currentCorridorDuration = 0;
    }
    else
    {
        currentCorridorDuration += checkingBreak;
        if(currentCorridorDuration >= corridorDuration)
        {
            digitalWrite(corridorLED_1, LOW);
            digitalWrite(corridorLED_2, LOW);
        }
    }
}

void living_room_gathering_scene()
{
    if(receive_infrared(livingRoomInfraredReceiver))
    {
        livingRoomSwitch = livingRoomSwitch ? false : true;
    }
    
    if(overallSwitch && livingRoomSwitch)
    {
        if(human_detection(livingRoomHumanDetection))
        {
            currentLivingoomDuration = 0;
            digitalWrite(livingRoomLED_1, HIGH);
            delay(500);
            digitalWrite(livingRoomLED_1, LOW);
            delay(500);
            
            digitalWrite(livingRoomLED_2, HIGH);
            delay(500);
            digitalWrite(livingRoomLED_2, LOW);
            delay(500);
            
            digitalWrite(livingRoomLED_3, HIGH);
            delay(500);
            digitalWrite(livingRoomLED_3, LOW);
            delay(500);
            
            digitalWrite(livingRoomLED_4, HIGH);
            delay(500);
            digitalWrite(livingRoomLED_4, LOW);
            delay(500);

            digitalWrite(livingRoomLED_5, HIGH);
            delay(500);
            digitalWrite(livingRoomLED_5, LOW);
            delay(500);

            digitalWrite(livingRoomLED_6, HIGH);
            delay(500);
            digitalWrite(livingRoomLED_6, LOW);
            delay(500);
        }
    }
}

void emergency_scene()
{
    // When in emergency, the LEDs will blink quickly
    while(true)
    {
        digitalWrite(bedroomLED_1, HIGH);
        delay(100);
        digitalWrite(bedroomLED_1, LOW);
        delay(100);
        
        digitalWrite(balconyLED_1, HIGH);
        delay(100);
        digitalWrite(balconyLED_1, LOW);
        delay(100);

        digitalWrite(livingRoomLED_1, HIGH);
        delay(100);
        digitalWrite(livingRoomLED_1, LOW);
        delay(100);

        digitalWrite(diningRoomLED_1, HIGH);
        delay(100);
        digitalWrite(diningRoomLED_1, LOW);
        delay(100);

        digitalWrite(bathroomLED_1, HIGH);
        delay(100);
        digitalWrite(bathroomLED_1, LOW);
        delay(100);

        digitalWrite(kitchenLED_1, HIGH);
        delay(100);
        digitalWrite(kitchenLED_1, LOW);
        delay(100);
    }
}

// change the scene
String receive_user_input()
{
	if (Serial.available() > 0)
	{
        String command = Serial.readString();
        if(command.equals("start"))
        {
            overall_control(true);
            Serial.println("All components have been started!");
        }
        else if(command.equals("stop"))
        {
            overall_control(false);
            Serial.println("All components have been stopped!");
        }
        else if(command.equals("bedroom"))
        {
            bedroomSwitch = true;
            Serial.println("The bedroom scene has been started!");
        }
        else if(command.equals("balcony"))
        {
            balconySwitch = true;
            Serial.println("The balcony scene has been started!");
        }
        else if(command.equals("living room"))
        {
            livingRoomSwitch = true;
            Serial.println("The living room scene has been started!");
        }
        else if(command.equals("dining room"))
        {
            diningRoomSwitch = true;
            Serial.println("The dining room scene has been started!");
        }
        else if(command.equals("bathroom"))
        {
            bathroomSwitch = true;
            Serial.println("The bathroom scene has been started!");
        }
        else if(command.equals("kitchen"))
        {
            kitchenSwitch = true;
            Serial.println("The kitchen scene has been started!");
        }
        else if(command.equals("gathering"))
        {
            kitchenSwitch = true;
            Serial.println("The living room gathering scene has been started!");
        }
        else if(command.equals("emergency"))
        {
            kitchenSwitch = true;
            Serial.println("The emergency scene has been started!");
        }
        else
        {
            Serial.println("Your input is invalid!");
        }
	}
	delay(5);
}

void control_modular()
{
    receive_user_input();
    if(overallSwitch)
    {
        bedroom_scene();
        balcony_scene();
        living_room_scene();
        dining_room_scene();
        bathroom_scene();
        kitchen_scene();
        living_room_gathering_scene();
    }
    corridor_scene();
    emergency_scene();
}


void loop()
{
    control_modular();
    delay(checkingBreak);
}
