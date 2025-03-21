#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define constants
#define PASSWORD "1234"

// Global variables for house status
int lightsOn = 0;
float temperature = 25.0;
int motionDetected = 0;
int securityStatus = 0; // 1 = Armed, 0 = Disarmed

// Function prototypes
void initializeSystem();
void displayMenu();
void controlLights();
void readTemperature();
void detectMotion();
void securitySystem();
void analyzeHouseStatus();

int main() {
    initializeSystem();

    int choice;
    while (1) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: controlLights(); break;
            case 2: readTemperature(); break;
            case 3: detectMotion(); break;
            case 4: securitySystem(); break;
            case 5: analyzeHouseStatus(); break;
            case 0: 
                printf("Exiting system...\n");
                exit(0);
            default: 
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

// Function to initialize the system
void initializeSystem() {
    printf("Initializing House Station System...\n");
    printf("System Ready! ✅\n\n");
}

// Function to display the menu
void displayMenu() {
    printf("\n===== HOUSE CONTROL MENU =====\n");
    printf("1. Control Lights\n");
    printf("2. Read Temperature\n");
    printf("3. Detect Motion\n");
    printf("4. Security System\n");
    printf("5. Analyze House Status\n");
    printf("0. Exit\n");
    printf("==============================\n");
}

// Function to control lights
void controlLights() {
    printf("\nLights are currently %s.\n", lightsOn ? "ON" : "OFF");
    printf("Enter 1 to turn ON or 0 to turn OFF: ");
    scanf("%d", &lightsOn);
    printf("Lights are now %s.\n", lightsOn ? "ON" : "OFF");
}

// Function to read temperature (Simulated input)
void readTemperature() {
    printf("\nEnter current temperature (°C): ");
    scanf("%f", &temperature);
    printf("Temperature recorded: %.2f°C\n", temperature);
}

// Function to detect motion (Simulated input)
void detectMotion() {
    printf("\nEnter 1 if motion is detected, 0 otherwise: ");
    scanf("%d", &motionDetected);
    if (motionDetected) {
        printf("🚨 Motion detected! Security Alert!\n");
    } else {
        printf("No motion detected.\n");
    }
}

// Function for security system authentication
void securitySystem() {
    char input[10];

    printf("\nEnter Security Password: ");
    scanf("%s", input);

    if (strcmp(input, PASSWORD) == 0) {
        securityStatus = !securityStatus; // Toggle security status
        printf("Security System %s!\n", securityStatus ? "Armed 🔒" : "Disarmed 🔓");
    } else {
        printf("Access Denied! 🚨 Incorrect password!\n");
    }
}

// Function to analyze house status
void analyzeHouseStatus() {
    printf("\n===== HOUSE STATUS ANALYSIS =====\n");
    printf("Lights: %s\n", lightsOn ? "ON 💡" : "OFF 🌑");
    printf("Temperature: %.2f°C %s\n", temperature, (temperature > 30.0 ? "🔥 (High)" : (temperature < 10.0 ? "❄️ (Low)" : "✅ (Normal)")));
    printf("Motion Detected: %s\n", motionDetected ? "🚨 Yes" : "✅ No");
    printf("Security System: %s\n", securityStatus ? "🔒 Armed" : "🔓 Disarmed");
    printf("=================================\n");
}
