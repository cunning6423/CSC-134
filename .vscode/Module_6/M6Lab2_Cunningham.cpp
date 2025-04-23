/*
CSC=134
M6Lab2
Cunningham
4/23/2025
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Define constants for directions
enum Direction {
    NORTH = 0,
    EAST = 1,
    SOUTH = 2,
    WEST = 3,
    NUM_DIRECTIONS = 4
};

// Direction strings for output
const string DIRECTION_NAMES[NUM_DIRECTIONS] = {
    "north", "east", "south", "west"
};

// Define constants for rooms
enum Room {
    ENTRANCE_HALL = 0,
    LIBRARY = 1,
    KITCHEN = 2,
    GARDEN = 3,
    BACKDOOR = 4,
    BACKYARD = 5,
    FOREST = 6,
    NUM_ROOMS = 7
};

int main() {
    // Room names array
    string roomNames[NUM_ROOMS] = {
        "Entrance Hall",
        "Library",
        "Kitchen",
        "Garden",
        "Backdoor",
        "Backyard",
        "Forest"
    };
    
    // Room descriptions array
    string roomDescriptions[NUM_ROOMS] = {
        "A grand entrance hall with a dusty chandelier hanging above.",
        "Walls lined with ancient books. The air smells of old paper.",
        "A spacious kitchen with an old stove and wooden counter.",
        "An overgrown garden with stone pathways and a small fountain.",
        "An ancient wooden door unopen with a dusty door knob.",
        "A expansive forest covered with dark green foliage.",
        "A forest of large trees, hanging vines, and wet grass."
    };
    
    // Adjacency list using a 2D array
    // connections[from_room][direction] = to_room or -1 if no connection
    int connections[NUM_ROOMS][NUM_DIRECTIONS];
    
    // Initialize all connections to -1 (no connection)
    for (int i = 0; i < NUM_ROOMS; i++) {
        for (int j = 0; j < NUM_DIRECTIONS; j++) {
            connections[i][j] = -1;
        }
    }
    
    // Define the connections between rooms using the Room enum
    // Entrance Hall connections
    connections[ENTRANCE_HALL][NORTH] = LIBRARY;    // Entrance Hall -> North -> Library
    connections[ENTRANCE_HALL][EAST] = KITCHEN;     // Entrance Hall -> East -> Kitchen
    connections[ENTRANCE_HALL][SOUTH] = -1;         // No connection south
    connections[ENTRANCE_HALL][WEST] = GARDEN;      // Entrance Hall -> West -> Garden
    
    // Library connections
    connections[LIBRARY][NORTH] = -1;               // No connection north
    connections[LIBRARY][EAST] = -1;                // No connection east
    connections[LIBRARY][SOUTH] = ENTRANCE_HALL;    // Library -> South -> Entrance Hall
    connections[LIBRARY][WEST] = -1;                // No connection west
    
    // Kitchen connections
    connections[KITCHEN][NORTH] = -1;               // No connection north
    connections[KITCHEN][EAST] = BACKDOOR;     // Kitchen -> South -> Backdoor
    connections[KITCHEN][SOUTH] = -1;               // No connection south
    connections[KITCHEN][WEST] = ENTRANCE_HALL;     // Kitchen -> West -> Entrance Hall
    
    // Garden connections
    connections[GARDEN][NORTH] = -1;                // No connection north
    connections[GARDEN][EAST] = ENTRANCE_HALL;      // Garden -> East -> Entrance Hall
    connections[GARDEN][SOUTH] = -1;                // No connection south
    connections[GARDEN][WEST] = -1;                 // No connection west
    
    // BackDoor connections
    connections[BACKDOOR][NORTH] = KITCHEN;         // Backdoor -> North -> Kitchen
    connections[BACKDOOR][EAST] = BACKYARD;         // Backdoor -> East -> BackYard
    connections[BACKDOOR][SOUTH] = -1;              // No connection south
    connections[BACKDOOR][WEST] = -1;               // No connection west
    
    // BackYard connections
    connections[BACKYARD][NORTH] = -1;              // No connection North
    connections[BACKYARD][EAST] = -1;               // No connection East
    connections[BACKYARD][SOUTH] = FOREST;   // Backdoor -> South -> Forest
    connections[BACKYARD][WEST] = KITCHEN;   //Backdoor -> west -> Kitchen

    // Forest connections
    connections[FOREST][NORTH] = BACKYARD;    // Backdoor -> north - > backYard
    connections[FOREST][EAST] = -1;               // No connection East
    connections[FOREST][SOUTH] = -1;              // No connection East
    connections[FOREST][WEST] = -1;               // No connection East
    
    // Game state
    int currentRoom = ENTRANCE_HALL; // Start in the Entrance Hall
    bool gameRunning = true;
    
    // Game loop
    while (gameRunning) {
        // Display current room information
        cout << "\nYou are in the " << roomNames[currentRoom] << endl;
        cout << roomDescriptions[currentRoom] << endl;
        
        // Show available exits
        cout << "Exits: ";
        bool hasExits = false;
        for (int dir = 0; dir < NUM_DIRECTIONS; dir++) {
            if (connections[currentRoom][dir] != -1) {
                cout << DIRECTION_NAMES[dir] << " ";
                hasExits = true;
            }
        }
        if (!hasExits) {
            cout << "none";
        }
        cout << endl;
        
        // Get player input
        string command;
        cout << "\nWhat would you like to do? ";
        cin >> command;
        
        // Process movement commands
        if (command == "north" || command == "n") {
            if (connections[currentRoom][NORTH] != -1) {
                currentRoom = connections[currentRoom][NORTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "east" || command == "e") {
            if (connections[currentRoom][EAST] != -1) {
                currentRoom = connections[currentRoom][EAST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "south" || command == "s") {
            if (connections[currentRoom][SOUTH] != -1) {
                currentRoom = connections[currentRoom][SOUTH];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "west" || command == "w") {
            if (connections[currentRoom][WEST] != -1) {
                currentRoom = connections[currentRoom][WEST];
            } else {
                cout << "You can't go that way." << endl;
            }
        } else if (command == "quit" || command == "q") {
            gameRunning = false;
        } else {
            cout << "I don't understand that command." << endl;
        }
    }
    
    cout << "Thanks for playing!" << endl;
    return 0;
}