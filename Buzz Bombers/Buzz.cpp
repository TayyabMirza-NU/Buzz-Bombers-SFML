#include <iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include<cstdlib>
#include<ctime>
#include<fstream>


using namespace std;
using namespace sf;

// Initializing Dimensions.
// resolutionX and resolutionY determine the rendering resolution.

const int resolutionX = 960;
const int resolutionY = 640;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int gameRows = resolutionX / boxPixelsX; // Total rows on grid
const int gameColumns = resolutionY / boxPixelsY; // Total columns on grid

// Initializing GameGrid.
int gameGrid[gameRows][gameColumns] = {};





void drawPlayer(RenderWindow& window, float& player_x, float& player_y, Sprite& playerSprite);

void MovePlayer(float& player_x, Clock& movementClock, float obstacleX[], float obstacleY[], int& remainingLives);
void drawBullet(RenderWindow& window, float& bullet_x, float& bullet_y, Sprite& bulletSprite);

void moveBullet(float& bullet_y, bool& bullet_exists, Clock& bulletClock, Music& bgMusic);

void Firing(bool& bullet_exists, float& bullet_x, float& bullet_y, float player_x, float player_y, bool& spacePressed, Music& fireSound, Music& bgMusic, int& remainingFires, int& firedBullets, int& remainingLives, RectangleShape& magazine, int& magazineBlock);

void RegularBeesManager(RenderWindow& window, Clock& regularBeeNext, int& current_R_bees, const int max_R_bees, bool R_bee_exist[], Sprite regularBeeSprite[], float R_bee_x[], float R_bee_y[], int beeDirection[], float Y_honeycomb_x[], float Y_honeycomb_y[], bool Y_honeycomb_exist[], Clock beeStay[], float Hive_x[], float Hive_y[], bool BeeHive_exist[], float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], const int rand_combs, Clock& R_bees_animation, float R_honeycomb_x[], float R_honeycomb_y[], bool R_honeycomb_exist, int current_K_bees);

void updateGrid(float player_x, float player_y, float bullet_x, float bullet_y, float R_bee_x[], float R_bee_y[], bool R_bee_exist[], int beeCount, float Y_honeycomb_x[], float Y_honeycomb_y[], float K_bee_x[], float K_bee_y[], bool K_bee_exist[], int k_beeCount, float R_honeycomb_x[], float R_honeycomb_y[], bool& bullet_exists, Music& bgMusic, Music& hitSound, bool Y_honeycomb_exist[], bool R_honeycomb_exist[], float Hive_x[], float Hive_y[], bool HiveStatus[], float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], unsigned int& score, const int rand_combs);



void obstaclesManager(RenderWindow& window, Sprite obstacleSprite[], float beeX[], float beeY[], int current_R_bees, bool R_bees_exist[], float obstacleX[], float obstacleY[], int& obstacleCount, float& player_x, float K_bee_x[], float K_bee_y[], bool K_bees_exist[], int& space, int& Left, int& Right, int kill_beeCount);

void humminbirdManager(
    RenderWindow& window, Clock& Bird, Clock& BirdMove, Sprite& BirdSprite,
    float& bird_x, float& bird_y, float honeycomb_x[], float honeycomb_y[],
    bool honeycomb_exist[], int current_R_bees, bool SickStatus,
    float K_honeycomb_x[], float K_honeycomb_y[], bool K_honeycomb_exist[],
    int Kill_beeCount, unsigned int& score, float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], const int rand_combs
);

//For Boss Level
void humminbirdManager(RenderWindow& window, Clock& Bird, Clock& BirdMove, Sprite& BirdSprite, float& bird_x, float& bird_y, float honeycomb_x[], float honeycomb_y[], bool honeycomb_exist[], int current_R_bees, bool SickStatus, float K_honeycomb_x[], float K_honeycomb_y[], bool K_honeycomb_exist[], int Kill_beeCount, unsigned int& score, float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], const int rand_combs, float power_up_x[], float power_up_y[], bool powerUp_exist[], int& powerup_count, Clock powerUpVisible[]);

void HummingBird_Health(float& bullet_x, float& bullet_y, float& bird_x, float& bird_y, bool& SickStatus, bool& bullet_exist, Sprite& BirdSprite, Clock& SickTime, Music& BirdHitSound, Music& bgMusic);

void BeeHivesManager(RenderWindow& window, Sprite HiveSprite[], bool BeeHive_exist, float Hive_x[], float Hive_y[]);

int BeeHiveCheck(float R_bee_x, float R_bee_y, float Hive_x[], float Hive_y[], int current_R_bees, float Y_honeycomb_x[], float Y_honeycomb_y[], bool Y_honeycomb_exist[], bool BeeHive_exist[]);

void KillerBeesManager(RenderWindow& window, Clock& KillerBeeNext, int& current_K_bees, const int max_K_bees, bool K_bee_exist[], Sprite KillerBeeSprite[], float K_bee_x[], float K_bee_y[], int K_beeDirection[], float R_honeycomb_x[], float R_honeycomb_y[], bool R_honeycomb_exist[]);


void DrawingHives(RenderWindow& window, Sprite HiveSprite[], float Hive_x[], float Hive_y[], bool BeeHive_exist[], int current_R_bees);

void Drawing_Red_Combs(RenderWindow& window, Sprite R_honeycombSprite[], float R_honeycomb_x[], float R_honeycomb_y[], bool R_honeycomb_exist[], int Kill_bees_count);

void Drawing_Yellow_Combs(RenderWindow& window, Sprite Y_honeycombSprite[], float Y_honeycomb_x[], float Y_honeycomb_y[], bool Y_honeycomb_exist[], int current_R_bees);

void Drawing_random_Combs(RenderWindow& window, Sprite rand_combSprite[], float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], int rand_combs);




void spawnPowerUps(Texture& Speed_Inc, Texture& Speed_Dec, Texture& Height_Inc, Texture& Height_Dec, Sprite PowerUpSprite[], float power_up_x[], float power_up_y[], bool powerUp_exist[], int& powerup_count, RenderWindow& window, Clock powerUpVisible[], float bullet_x, float bullet_y, bool& bullet_exists, float R_honeycomb_x[], float R_honeycomb_y[], bool R_honeycomb_exist[], int k_beeCount, float& player_x, float& player_y, float obstacleX[], Sprite& playerSprite, int& remainingLives);




void BirdPowerUp(int x, int y, float power_up_x[], float power_up_y[], bool powerUp_exist[], int& powerup_count, Clock powerUpVisible[]);

/////////////////////////////////////////////////////////////////////////////
//                                                                         //
// Write your functions declarations here. Some have been written for you. //
//                                                                         //
/////////////////////////////////////////////////////////////////////////////

void Level_One(RenderWindow& window, bool& inLevel1, int& remainingLives, unsigned int& score, int& nextdicision, int& beehivescores);
void Level_Two(RenderWindow& window, bool& inLevel2, int& remainingLives, unsigned int& score, int& nextdicision, int& beehivescores);

void Level_Three(RenderWindow& window, bool& inLevel3, int& remainingLives, unsigned int& score, int& nextdicision, int& beehivescores);


void Boss_Level(RenderWindow& window, bool& inLevel4, int& remainingLives, unsigned int& score, int& nextdicision, int& beehivescores);



void viewScoreboard(RenderWindow& window, Font& font) {
    ifstream file("scores.txt");
    string lines[100];
    int scores[100];
    int count = 0;

    if (file.is_open()) {
        while (file >> lines[count] >> scores[count]) {
            count++;
        }
        file.close();
    }


    for (int i = 0; i < count - 1; i++) {
        for (int j = i + 1; j < count; j++) {
            if (scores[i] < scores[j]) {

                int tempScore = scores[i];
                scores[i] = scores[j];
                scores[j] = tempScore;


                string tempLine = lines[i];
                lines[i] = lines[j];
                lines[j] = tempLine;
            }
        }
    }


    window.clear();
    Text title("Scoreboard", font, 50);
    title.setPosition(300, 50);
    title.setFillColor(Color::Red);
    window.draw(title);

    for (int i = 0; i < count && i < 10; ++i) {
        Text scoreText(lines[i] + ": \t\t\t\t\t\t" + to_string(scores[i]), font, 30);
        scoreText.setPosition(300, 150 + i * 40);
        scoreText.setFillColor(Color::White);
        window.draw(scoreText);
    }

    Text instruction("Press ESC to return to menu", font, 20);
    instruction.setPosition(300, 600);
    instruction.setFillColor(Color::White);
    window.draw(instruction);
    window.display();

    while (true) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return;
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                return;
            }
        }
    }
}

string getPlayerName(RenderWindow& window, Font& font) {
    string playerName;
    Text nameText("", font, 30);
    nameText.setPosition(300, 300);
    nameText.setFillColor(Color::White);

    Text instruction("Enter your name: ", font, 30);
    instruction.setPosition(300, 250);
    instruction.setFillColor(Color::White);

    while (true) {
        window.clear();
        window.draw(instruction);
        nameText.setString(playerName);
        window.draw(nameText);
        window.display();

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return "";
            }
            if (event.type == Event::TextEntered) {
                if (event.text.unicode == '\b' && !playerName.empty()) {
                    playerName.pop_back();
                }
                else if (event.text.unicode >= 32 && event.text.unicode <= 126) {
                    playerName += static_cast<char>(event.text.unicode);
                }
            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Enter) {
                return playerName;
            }
        }
    }
}

void saveScore(const string& name, unsigned int score) {
    ofstream file("scores.txt", ios::app);
    if (file.is_open()) {
        file << name << "  " << score << "\n";
        file.close();
    }
}




int main() {
    srand(time(0));

    RenderWindow window(VideoMode(resolutionX, resolutionY), "Buzz Bombers", Style::Close | Style::Titlebar);
    window.setPosition(Vector2i(500, 200));

    // Load font
    sf::Font font;
    if (!font.loadFromFile("Fonts/Jaro.ttf")) {
        std::cerr << "Error loading font!" << std::endl;
        return -1;
    }

    // Game states
    const int MAIN_MENU = 0;
    const int LEVEL_SELECT = 1;
    const int GAME = 2;
    const int EXIT = 3;

    int currentState = MAIN_MENU;
    int selectedIndex = 0;
    int selectedLevel = 1;
    string playerName;
    bool GetName = true;


    bool GameOver = false;
    bool inLevel1 = false;
    bool inLevel2 = false;
    bool inLevel3 = false;
    bool inLevel4 = false;
    int remainingLives = 3;
    unsigned int score = 0;
    int nextdecision = -1;
    int beehivescores = 0;

    bool twenty = false;
    bool forty = false;
    bool eighty = false;
    Text menu[4];
    string options[] = { "Start Game", "Select Level", "View Scoreboard", "Exit" };
    for (int i = 0; i < 4; ++i) {
        menu[i].setFont(font);
        menu[i].setString(options[i]);
        menu[i].setPosition(300, 200 + i * 50);
        menu[i].setCharacterSize(30);
        menu[i].setFillColor(Color::White);
    }


    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
                return 0;
            }




            if (currentState == MAIN_MENU) {

                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Down) {
                        selectedIndex = (selectedIndex + 1) % 4;
                    }
                    else if (event.key.code == Keyboard::Up) {
                        selectedIndex = (selectedIndex - 1 + 4) % 4;
                    }
                    else if (event.key.code == Keyboard::Enter) {
                        if (selectedIndex == 0) currentState = GAME;
                        else if (selectedIndex == 1) currentState = LEVEL_SELECT;
                        else if (selectedIndex == 2) viewScoreboard(window, font);
                        else if (selectedIndex == 3) window.close();
                    }
                }

                for (int i = 0; i < 4; ++i) {
                    menu[i].setFillColor(i == selectedIndex ? Color::Red : Color::White);
                }
            }


            else if (currentState == LEVEL_SELECT) {
                if (event.type == Event::KeyPressed) {
                    if (event.key.code == Keyboard::Left) {
                        selectedLevel = (selectedLevel == 1) ? 4 : selectedLevel - 1;
                    }
                    else if (event.key.code == Keyboard::Right) {
                        selectedLevel = (selectedLevel == 4) ? 1 : selectedLevel + 1;
                    }
                    else if (event.key.code == Keyboard::Enter) {
                        currentState = GAME;
                    }
                    else if (event.key.code == Keyboard::Escape) {
                        currentState = MAIN_MENU;
                    }
                }
            }

        }


        if (currentState == MAIN_MENU) {
            window.clear();

            for (int i = 0; i < 4; ++i) window.draw(menu[i]);
            window.display();
        }
        else if (currentState == LEVEL_SELECT) {
            window.clear();
            Text levelText;
            levelText.setFont(font);
            levelText.setString("Selected Level: " + std::to_string(selectedLevel));
            levelText.setCharacterSize(40);
            levelText.setPosition(250, 300);
            levelText.setFillColor(sf::Color::White);

            Text instructionText;
            instructionText.setFont(font);
            instructionText.setString("Use Left/Right to select level\nPress Enter to start\nPress Esc to go back");
            instructionText.setCharacterSize(20);
            instructionText.setPosition(250, 400);
            instructionText.setFillColor(sf::Color::White);

            window.draw(levelText);
            window.draw(instructionText);
            window.display();
        }
        else if (currentState == GAME) {

            if (GetName) {
                playerName = getPlayerName(window, font);
                GetName = false;
                if (playerName.empty()) {
                    currentState = MAIN_MENU;
                    GetName = true;
                    continue;
                }
            }

            // Start game logic
            if (selectedLevel == 1) {
                inLevel1 = true;
                while (inLevel1) {
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            window.close();
                            return 0;
                        }
                        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape) {
                            inLevel1 = false;
                            currentState = MAIN_MENU;
                        }
                    }
                    Level_One(window, inLevel1, remainingLives, score, nextdecision, beehivescores);

                    if (nextdecision == 1)
                    {
                        if (score > 20000 && !twenty) {
                            remainingLives++;
                            twenty = true;
                        }
                        if (score > 40000 && !forty) {
                            remainingLives++;
                            forty = true;
                        }
                        if (score > 80000 && !eighty) {
                            remainingLives++;
                            eighty = true;
                        }

                        score += beehivescores * 2000;

                        beehivescores = 0;

                        selectedLevel = 2;
                        inLevel2 = true;
                    }
                    else
                        GameOver = true;

                }
            }
            else if (selectedLevel == 2) {
                inLevel2 = true;
                while (inLevel2) {
                    while (window.pollEvent(event)) {
                        if (event.type == sf::Event::Closed) {
                            window.close();
                            return 0;
                        }
                        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                            inLevel2 = false;
                            currentState = MAIN_MENU;
                        }
                    }
                    Level_Two(window, inLevel2, remainingLives, score, nextdecision, beehivescores);
                    if (nextdecision == 2)
                    {

                        if (score > 20000 && !twenty) {
                            remainingLives++;
                            twenty = true;
                        }
                        if (score > 40000 && !forty) {
                            remainingLives++;
                            forty = true;
                        }
                        if (score > 80000 && !eighty) {
                            remainingLives++;
                            eighty = true;
                        }

                        score += beehivescores * 2000;
                        beehivescores = 0;

                        selectedLevel = 3;
                        inLevel3 = true;
                    }
                    else
                        GameOver = true;
                }
            }
            else if (selectedLevel == 3) {
                inLevel3 = true;
                while (inLevel3) {
                    while (window.pollEvent(event)) {
                        if (event.type == Event::Closed) {
                            window.close();
                            return 0;
                        }
                        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                            inLevel3 = false;
                            currentState = MAIN_MENU;
                        }
                    }
                    Level_Three(window, inLevel3, remainingLives, score, nextdecision, beehivescores);
                    if (nextdecision == 3)
                    {
                        if (score > 20000 && !twenty) {
                            remainingLives++;
                            twenty = true;
                        }
                        if (score > 40000 && !forty) {
                            remainingLives++;
                            forty = true;
                        }
                        if (score > 80000 && !eighty) {
                            remainingLives++;
                            eighty = true;
                        }

                        score += beehivescores * 2000;
                        beehivescores = 0;

                        selectedLevel = 4;
                        inLevel4 = true;
                    }
                    else
                        GameOver = true;
                }
            }
            else if (selectedLevel == 4) {
                inLevel4 = true;
                while (inLevel4) {
                    while (window.pollEvent(event)) {
                        if (event.type == Event::Closed) {
                            window.close();
                            return 0;
                        }
                        if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape) {
                            inLevel4 = false;
                            currentState = MAIN_MENU;
                        }
                    }
                    Boss_Level(window, inLevel4, remainingLives, score, nextdecision, beehivescores);
                    score += beehivescores * 2000;
                    beehivescores = 0;
                    GameOver = true;
                    nextdecision = -1;
                }
            }

            if (GameOver) {
                saveScore(playerName, score);
                viewScoreboard(window, font);
                score = 0;
                remainingLives = 3;
                currentState = MAIN_MENU;
                GetName = true;
                selectedLevel = 1;
                inLevel2 = inLevel3 = inLevel4 = false;
                twenty = forty = eighty = false;
            }
        }
    }
}








void Level_One(RenderWindow& window, bool& inLevel1, int& remainingLives, unsigned int& score, int& nextdicision, int& beehivescores) {

    Music bgMusic;
    if (!bgMusic.openFromFile("Music/Music3.ogg")) {
        cout << "Error: Could not load music file!" << endl;
    }
    bgMusic.setVolume(50);
    bgMusic.setLoop(true);
    bgMusic.play();

    Music fireSound;
    if (!fireSound.openFromFile("Sound Effects/fire.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    fireSound.setVolume(150);

    Music hitSound;
    if (!hitSound.openFromFile("Sound Effects/hit.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    hitSound.setVolume(100);


    // Initializing Player and Player Sprites.
    float player_x = (gameRows / 2) * boxPixelsX;
    float player_y = (gameColumns - 4) * boxPixelsY;

    Texture playerTexture;
    Sprite playerSprite;
    playerTexture.loadFromFile("Textures/spray.png");
    playerSprite.setTexture(playerTexture);
    Clock player_movClock;
    playerSprite.setTextureRect(IntRect(0, 0, boxPixelsX + 100, boxPixelsY + 100));


    float bullet_x = player_x;
    float bullet_y = player_y;
    bool bullet_exists = false;
    bool spacePressed = false;


    Clock bulletClock;
    Texture bulletTexture;
    Sprite bulletSprite;
    bulletTexture.loadFromFile("Textures/bullet.png");
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setScale(2, 2);
    bulletSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));





    const int max_R_bees = 20;
    Clock regularBeeNext;
    Texture regularBeeTexture;
    regularBeeTexture.loadFromFile("Sprites/BeeSheet.png");
    Sprite regularBeeSprite[max_R_bees];

    int current_R_bees = 0;
    float R_bee_x[max_R_bees];
    float R_bee_y[max_R_bees];
    bool R_bee_exist[max_R_bees];
    int beeDirection[max_R_bees];
    for (int i = 0; i < max_R_bees; i++)
    {

        regularBeeSprite[i].setTexture(regularBeeTexture);
        R_bee_exist[i] = false;
        // regularBeeSprite[i].setPosition(0.f, boxPixelsY);
        if (i & 1)
        {
            R_bee_x[i] = 0;
            R_bee_y[i] = boxPixelsY;
            beeDirection[i] = 1;
            regularBeeSprite[i].setScale(-1.8, 1.8);
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));
        }
        else {
            R_bee_x[i] = resolutionX;
            R_bee_y[i] = boxPixelsY;
            beeDirection[i] = -1;
            regularBeeSprite[i].setScale(1.8, 1.8);
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));
        }
    }







    const int max_Kill_bees = 1;
    Clock KillerBeeNext;
    Texture KillerBeeTexture;
    KillerBeeTexture.loadFromFile("Textures/Regular_bee.png");
    Sprite KillerBeeSprite[max_Kill_bees];

    int Kill_bees_count = 0;
    float K_bee_x[max_Kill_bees];
    float K_bee_y[max_Kill_bees];
    bool K_bee_exist[max_Kill_bees];
    int K_beeDirection[max_Kill_bees];
    for (int i = 0; i < max_Kill_bees; i++)
    {
        KillerBeeSprite[i].setTexture(KillerBeeTexture);
        K_bee_exist[i] = false;
        if (i & 1) {
            K_bee_x[i] = 0;
            K_bee_y[i] = boxPixelsY;
            K_beeDirection[i] = 1;
            KillerBeeSprite[i].setScale(-1.2, 1.2);
        }
        else {
            K_bee_x[i] = resolutionX;
            K_bee_y[i] = boxPixelsY;
            K_beeDirection[i] = -1;
            KillerBeeSprite[i].setScale(1.2, 1.2);
        }
    }


    Texture Y_honeycombTextute;
    Y_honeycombTextute.loadFromFile("Textures/honeycomb.png");
    Sprite Y_honeycombSprite[max_R_bees];
    bool Y_honeycomb_exist[max_R_bees];
    float Y_honeycomb_x[max_R_bees];
    float Y_honeycomb_y[max_R_bees];
    Clock BeeStay[max_R_bees];

    for (int i = 0; i < max_R_bees; i++)
    {
        Y_honeycombSprite[i].setTexture(Y_honeycombTextute);
        Y_honeycombSprite[i].setScale(0.8f, 0.8f);
        Y_honeycombSprite[i].setOrigin(15, 1);
        Y_honeycomb_x[i] = -64;
        Y_honeycomb_y[i] = -64;
        Y_honeycomb_exist[i] = false;
    }


    Texture R_honeycombTextute;
    R_honeycombTextute.loadFromFile("Textures/honeycomb_red.png");
    Sprite R_honeycombSprite[max_Kill_bees];
    bool R_honeycomb_exist[max_Kill_bees];
    float R_honeycomb_x[max_Kill_bees];
    float R_honeycomb_y[max_Kill_bees];
    Clock R_bees_animation;


    for (int i = 0; i < max_Kill_bees; i++)
    {
        R_honeycombSprite[i].setTexture(R_honeycombTextute);
        R_honeycombSprite[i].setScale(0.8f, 0.8f);
        R_honeycombSprite[i].setOrigin(15, 1);
        R_honeycomb_exist[i] = false;
    }

    const int rand_combs = 3;
    Sprite rand_combSprite[rand_combs];
    bool rand_comb_exist[rand_combs];
    float rand_comb_x[rand_combs];
    float rand_comb_y[rand_combs];

    for (int i = 0; i < rand_combs; i++)
    {
        rand_combSprite[i].setTexture(Y_honeycombTextute);
        rand_combSprite[i].setScale(0.8f, 0.8f);
        rand_combSprite[i].setOrigin(15, 1);
        rand_comb_x[i] = rand() % (resolutionX - boxPixelsX) + 10;
        rand_comb_y[i] = rand() % 460 + boxPixelsY;
        rand_comb_exist[i] = true;
    }

    Texture obstacleTexture;
    obstacleTexture.loadFromFile("Textures/obstacles.png");
    Sprite obstacleSprite[gameRows * 2];
    float obstacleY[gameRows * 2] = { 0 };
    float obstacleX[gameRows * 2] = { 0 };
    for (int i = 0; i < gameRows * 2; i++)
    {
        obstacleX[i] = -32;
        obstacleSprite[i].setTexture(obstacleTexture);
    }
    int obsatclesCounter = 0;
    int space = 1;
    int Left = 0;
    int Right = 1;

    Texture BirdTexture;
    BirdTexture.loadFromFile("Textures/bird.png");
    Sprite BirdSprite;
    BirdSprite.setTexture(BirdTexture);
    Music BirdhitSound;
    if (!BirdhitSound.openFromFile("Sound Effects/birdHit.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    BirdSprite.setScale(2.6, 2.5);
    BirdSprite.setColor(Color::Red);
    float bird_x = resolutionX - boxPixelsX;
    float bird_y = boxPixelsY;
    Clock Bird;
    Clock BirdMove;
    Clock SickTime;
    bool SickStatus = true;
    BirdMove.restart();


    Texture HivesTexture;
    HivesTexture.loadFromFile("Textures/hive.png");
    Sprite HiveSprite[max_R_bees];
    bool BeeHive_exist[max_R_bees];
    float Hive_x[max_R_bees];
    float Hive_y[max_R_bees];
    for (int i = 0; i < max_R_bees; i++)
    {
        Hive_x[i] = 0;
        Hive_y[i] = 0;
        BeeHive_exist[i] = false;
        HiveSprite[i].setTexture(HivesTexture);

    }

    Texture BackgroungL1;
    BackgroungL1.loadFromFile("Textures/background_L1.jpg");
    Sprite BG_L1;
    BG_L1.setTexture(BackgroungL1);
    BG_L1.setScale(1.4, 1.5);


    RectangleShape groundRectangle(Vector2f(960, 64));
    groundRectangle.setPosition(0, (gameColumns - 2) * boxPixelsY);
    groundRectangle.setFillColor(Color::Green);




    Font font;
    if (!font.loadFromFile("Fonts/Jaro.ttf")) {
        cout << "Error: Could not load font file!" << endl;

    }

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(35);
    scoreText.setFillColor(Color::White);
    scoreText.setStyle(Text::Bold);
    scoreText.setOutlineColor(Color::Black); // Set the border color
    scoreText.setOutlineThickness(2.0f);


    const int maxFires = 64;
    int remainingFires = maxFires;
    int firedBullets = 0;
    int magazineBlock = 1;

    RectangleShape magazine(Vector2f(boxPixelsY, boxPixelsY));
    magazine.setFillColor(Color::Yellow);

    // Lives setup (2 lives for spray)

    Texture lifeTexture;
    Sprite lifeSprite;
    lifeTexture.loadFromFile("Textures/spray.png");
    lifeSprite.setTexture(lifeTexture);
    lifeSprite.setColor(Color::Black);



    Clock Nextlevel;
    Clock Nextlevelwait;

    bool hivescorevalidator = true;

    while (inLevel1) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                bgMusic.stop();
                inLevel1 = false;
                return;
                window.close();

            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape || remainingLives == 0 || nextdicision == 1) {
                inLevel1 = false;

                bgMusic.stop();
                // levelSetup=0;
            }
        }


        bool allBeesDead = false;

        for (int i = 0; i < max_R_bees; i++) {
            if (Nextlevel.getElapsedTime() >= seconds(2)) {
                allBeesDead = true;
                if (R_bee_exist[i]) {
                    allBeesDead = false;
                    Nextlevelwait.restart();
                    break;
                }
            }
        }

        if (allBeesDead) {
            if (Nextlevelwait.getElapsedTime() >= seconds(7)) {
                nextdicision = 1;
                if (hivescorevalidator)
                    for (int i = 0; i < max_R_bees; i++)
                        if (BeeHive_exist[i])
                            beehivescores++;
                hivescorevalidator = false;

            }

        }


        window.draw(BG_L1);

        MovePlayer(player_x, player_movClock, obstacleX, obstacleY, remainingLives);

        Firing(bullet_exists, bullet_x, bullet_y, player_x, player_y, spacePressed, fireSound, bgMusic, remainingFires, firedBullets, remainingLives, magazine, magazineBlock);

        updateGrid(player_x, player_y, bullet_x, bullet_y, R_bee_x, R_bee_y, R_bee_exist, current_R_bees, Y_honeycomb_x, Y_honeycomb_y, K_bee_x, K_bee_y, K_bee_exist, Kill_bees_count, R_honeycomb_x, R_honeycomb_y, bullet_exists, bgMusic, hitSound, Y_honeycomb_exist, R_honeycomb_exist, Hive_x, Hive_y, BeeHive_exist, rand_comb_x, rand_comb_y, rand_comb_exist, score, rand_combs);

        HummingBird_Health(bullet_x, bullet_y, bird_x, bird_y, SickStatus, bullet_exists, BirdSprite, SickTime, BirdhitSound, bgMusic);

        Drawing_Yellow_Combs(window, Y_honeycombSprite, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, current_R_bees);

        Drawing_Red_Combs(window, R_honeycombSprite, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count);

        Drawing_random_Combs(window, rand_combSprite, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs);


        KillerBeesManager(window, KillerBeeNext, Kill_bees_count, max_Kill_bees, K_bee_exist, KillerBeeSprite, K_bee_x, K_bee_y, K_beeDirection, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist);

        humminbirdManager(window, Bird, BirdMove, BirdSprite, bird_x, bird_y, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, current_R_bees, SickStatus, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count, score, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs);

        RegularBeesManager(window, regularBeeNext, current_R_bees, max_R_bees, R_bee_exist, regularBeeSprite, R_bee_x, R_bee_y, beeDirection, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, BeeStay, Hive_x, Hive_y, BeeHive_exist, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs, R_bees_animation, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count);




        obstaclesManager(window, obstacleSprite, R_bee_x, R_bee_y, current_R_bees, R_bee_exist, obstacleX, obstacleY, obsatclesCounter, player_x, K_bee_x, K_bee_y, K_bee_exist, space, Left, Right, Kill_bees_count);


        DrawingHives(window, HiveSprite, Hive_x, Hive_y, BeeHive_exist, current_R_bees);



        if (bullet_exists == true) {
            moveBullet(bullet_y, bullet_exists, bulletClock, bgMusic);
            drawBullet(window, bullet_x, bullet_y, bulletSprite);
        }
        else {
            bullet_x = player_x;
            bullet_y = player_y;
        }

        magazine.setPosition(player_x + 15, player_y + boxPixelsY);
        window.draw(magazine);
        drawPlayer(window, player_x, player_y, playerSprite);
        window.draw(groundRectangle);

        for (int i = 1; i < remainingLives; i++) {
            lifeSprite.setPosition(i * 50, resolutionY - boxPixelsX * 2);
            window.draw(lifeSprite);
        }

        scoreText.setString("Score: " + to_string(score));
        scoreText.setPosition(resolutionX - boxPixelsX * 7 - 10, resolutionY - boxPixelsY - 20);
        window.draw(scoreText);

        window.display();
        window.clear();
    }

}







void Level_Two(RenderWindow& window, bool& inLevel2, int& remainingLives, unsigned int& score, int& nextdicision, int& beehivescores) {

    Music bgMusic;
    if (!bgMusic.openFromFile("Music/cave.ogg")) {
        cout << "Error: Could not load music file!" << endl;
    }
    bgMusic.setVolume(50);
    bgMusic.setLoop(true);
    bgMusic.play();

    Music fireSound;
    if (!fireSound.openFromFile("Sound Effects/fire.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    fireSound.setVolume(150);

    Music hitSound;
    if (!hitSound.openFromFile("Sound Effects/hit.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    hitSound.setVolume(100);


    // Initializing Player and Player Sprites.
    float player_x = (gameRows / 2) * boxPixelsX;
    float player_y = (gameColumns - 4) * boxPixelsY;

    Texture playerTexture;
    Sprite playerSprite;
    playerTexture.loadFromFile("Textures/spray.png");
    playerSprite.setTexture(playerTexture);
    Clock player_movClock;
    playerSprite.setTextureRect(IntRect(0, 0, boxPixelsX + 100, boxPixelsY + 100));


    float bullet_x = player_x;
    float bullet_y = player_y;
    bool bullet_exists = false;
    bool spacePressed = false;


    Clock bulletClock;
    Texture bulletTexture;
    Sprite bulletSprite;
    bulletTexture.loadFromFile("Textures/bullet.png");
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setScale(2, 2);
    bulletSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));





    const int max_R_bees = 15;
    Clock regularBeeNext;
    Texture regularBeeTexture;
    regularBeeTexture.loadFromFile("Sprites/BeeSheet.png");
    Sprite regularBeeSprite[max_R_bees];

    int current_R_bees = 0;
    float R_bee_x[max_R_bees];
    float R_bee_y[max_R_bees];
    bool R_bee_exist[max_R_bees];
    int beeDirection[max_R_bees];
    for (int i = 0; i < max_R_bees; i++)
    {

        regularBeeSprite[i].setTexture(regularBeeTexture);
        R_bee_exist[i] = false;
        // regularBeeSprite[i].setPosition(0.f, boxPixelsY);
        if (i & 1)
        {
            R_bee_x[i] = 0;
            R_bee_y[i] = boxPixelsY;
            beeDirection[i] = 1;
            regularBeeSprite[i].setScale(-1.8, 1.8);
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));
        }
        else {
            R_bee_x[i] = resolutionX;
            R_bee_y[i] = boxPixelsY;
            beeDirection[i] = -1;
            regularBeeSprite[i].setScale(1.8, 1.8);
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));
        }
    }







    const int max_Kill_bees = 5;
    Clock KillerBeeNext;
    Texture KillerBeeTexture;
    KillerBeeTexture.loadFromFile("Textures/Regular_bee.png");
    Sprite KillerBeeSprite[max_Kill_bees];

    int Kill_bees_count = 0;
    float K_bee_x[max_Kill_bees];
    float K_bee_y[max_Kill_bees];
    bool K_bee_exist[max_Kill_bees];
    int K_beeDirection[max_Kill_bees];
    for (int i = 0; i < max_Kill_bees; i++)
    {
        KillerBeeSprite[i].setTexture(KillerBeeTexture);
        K_bee_exist[i] = false;
        if (i & 1) {
            K_bee_x[i] = 0;
            K_bee_y[i] = boxPixelsY;
            K_beeDirection[i] = 1;
            KillerBeeSprite[i].setScale(-1.2, 1.2);
        }
        else {
            K_bee_x[i] = resolutionX;
            K_bee_y[i] = boxPixelsY;
            K_beeDirection[i] = -1;
            KillerBeeSprite[i].setScale(1.2, 1.2);
        }
    }


    Texture Y_honeycombTextute;
    Y_honeycombTextute.loadFromFile("Textures/honeycomb.png");
    Sprite Y_honeycombSprite[max_R_bees];
    bool Y_honeycomb_exist[max_R_bees];
    float Y_honeycomb_x[max_R_bees];
    float Y_honeycomb_y[max_R_bees];
    Clock BeeStay[max_R_bees];

    for (int i = 0; i < max_R_bees; i++)
    {
        Y_honeycombSprite[i].setTexture(Y_honeycombTextute);
        Y_honeycombSprite[i].setScale(0.8f, 0.8f);
        Y_honeycombSprite[i].setOrigin(15, 1);
        Y_honeycomb_x[i] = -64;
        Y_honeycomb_y[i] = -64;
        Y_honeycomb_exist[i] = false;
    }

    Texture R_honeycombTextute;
    R_honeycombTextute.loadFromFile("Textures/honeycomb_red.png");
    Sprite R_honeycombSprite[max_Kill_bees];
    bool R_honeycomb_exist[max_Kill_bees];
    float R_honeycomb_x[max_Kill_bees];
    float R_honeycomb_y[max_Kill_bees];
    Clock R_bees_animation;


    for (int i = 0; i < max_Kill_bees; i++)
    {
        R_honeycombSprite[i].setTexture(R_honeycombTextute);
        R_honeycombSprite[i].setScale(0.8f, 0.8f);
        R_honeycombSprite[i].setOrigin(15, 1);
        R_honeycomb_exist[i] = false;
    }

    const int rand_combs = 9;
    Sprite rand_combSprite[rand_combs];
    bool rand_comb_exist[rand_combs];
    float rand_comb_x[rand_combs];
    float rand_comb_y[rand_combs];

    for (int i = 0; i < rand_combs; i++)
    {
        rand_combSprite[i].setTexture(Y_honeycombTextute);
        rand_combSprite[i].setScale(0.8f, 0.8f);
        rand_combSprite[i].setOrigin(15, 1);

        rand_comb_x[i] = rand() % (resolutionX - boxPixelsX) + 10;
        rand_comb_y[i] = rand() % 460 + boxPixelsY;
        rand_comb_exist[i] = true;
    }

    Texture obstacleTexture;
    obstacleTexture.loadFromFile("Textures/obstacles.png");
    Sprite obstacleSprite[gameRows * 2];
    float obstacleY[gameRows * 2] = { 0 };
    float obstacleX[gameRows * 2] = { 0 };
    for (int i = 0; i < gameRows * 2; i++)
    {
        obstacleX[i] = -32;
        obstacleSprite[i].setTexture(obstacleTexture);
    }
    int obsatclesCounter = 0;
    int space = 1;
    int Left = 0;
    int Right = 1;

    Texture BirdTexture;
    BirdTexture.loadFromFile("Textures/bird.png");
    Sprite BirdSprite;
    BirdSprite.setTexture(BirdTexture);
    Music BirdhitSound;
    if (!BirdhitSound.openFromFile("Sound Effects/birdHit.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    BirdSprite.setScale(2.6, 2.5);
    BirdSprite.setColor(Color::Red);
    float bird_x = resolutionX - boxPixelsX;
    float bird_y = boxPixelsY;
    Clock Bird;
    Clock BirdMove;
    Clock SickTime;
    bool SickStatus = true;
    BirdMove.restart();


    Texture HivesTexture;
    HivesTexture.loadFromFile("Textures/hive.png");
    Sprite HiveSprite[max_R_bees];
    bool BeeHive_exist[max_R_bees];
    float Hive_x[max_R_bees];
    float Hive_y[max_R_bees];
    for (int i = 0; i < max_R_bees; i++)
    {
        Hive_x[i] = 0;
        Hive_y[i] = 0;
        BeeHive_exist[i] = false;
        HiveSprite[i].setTexture(HivesTexture);

    }

    Texture BackgroungL1;
    BackgroungL1.loadFromFile("Textures/background_L1.jpg");
    Sprite BG_L1;
    BG_L1.setTexture(BackgroungL1);
    BG_L1.setScale(1.4, 1.5);


    RectangleShape groundRectangle(Vector2f(960, 64));
    groundRectangle.setPosition(0, (gameColumns - 2) * boxPixelsY);
    groundRectangle.setFillColor(Color::Green);




    Font font;
    if (!font.loadFromFile("Fonts/Jaro.ttf")) {
        cout << "Error: Could not load font file!" << endl;

    }

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(35);
    scoreText.setFillColor(Color::White);
    scoreText.setStyle(Text::Bold);
    scoreText.setOutlineColor(Color::Black); // Set the border color
    scoreText.setOutlineThickness(2.0f);


    const int maxFires = 64;
    int remainingFires = maxFires;
    int firedBullets = 0;
    int magazineBlock = 1;

    RectangleShape magazine(Vector2f(boxPixelsY, boxPixelsY));
    magazine.setFillColor(Color::Yellow);



    Texture lifeTexture;
    Sprite lifeSprite;
    lifeTexture.loadFromFile("Textures/spray.png");
    lifeSprite.setTexture(lifeTexture);
    lifeSprite.setColor(Color::Black);



    Clock Nextlevel;
    Clock Nextlevelwait;


    bool hivescorevalidator = true;
    while (inLevel2) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                bgMusic.stop();
                inLevel2 = false;
                return;
                window.close();

            }
            if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape || remainingLives == 0 || nextdicision == 2) {
                inLevel2 = false;

                bgMusic.stop();
                // levelSetup=0;
            }
        }


        bool allBeesDead = true;


        for (int i = 0; i < max_R_bees; i++) {
            if (Nextlevel.getElapsedTime() >= seconds(2)) {
                if (R_bee_exist[i]) {
                    allBeesDead = false;
                    Nextlevelwait.restart();
                    break;
                }
            }
        }


        if (allBeesDead) {
            for (int i = 0; i < max_Kill_bees; i++) {
                if (Nextlevel.getElapsedTime() >= seconds(2)) {
                    if (K_bee_exist[i]) {
                        allBeesDead = false;
                        Nextlevelwait.restart();
                        break;
                    }
                }
            }
        }


        if (allBeesDead) {
            if (Nextlevelwait.getElapsedTime() >= seconds(7)) {
                nextdicision = 2;
                if (hivescorevalidator)
                    for (int i = 0; i < max_R_bees; i++)
                        if (BeeHive_exist[i])
                            beehivescores++;
                hivescorevalidator = false;

            }

        }



        window.draw(BG_L1);

        MovePlayer(player_x, player_movClock, obstacleX, obstacleY, remainingLives);

        Firing(bullet_exists, bullet_x, bullet_y, player_x, player_y, spacePressed, fireSound, bgMusic, remainingFires, firedBullets, remainingLives, magazine, magazineBlock);

        updateGrid(player_x, player_y, bullet_x, bullet_y, R_bee_x, R_bee_y, R_bee_exist, current_R_bees, Y_honeycomb_x, Y_honeycomb_y, K_bee_x, K_bee_y, K_bee_exist, Kill_bees_count, R_honeycomb_x, R_honeycomb_y, bullet_exists, bgMusic, hitSound, Y_honeycomb_exist, R_honeycomb_exist, Hive_x, Hive_y, BeeHive_exist, rand_comb_x, rand_comb_y, rand_comb_exist, score, rand_combs);

        HummingBird_Health(bullet_x, bullet_y, bird_x, bird_y, SickStatus, bullet_exists, BirdSprite, SickTime, BirdhitSound, bgMusic);

        Drawing_Yellow_Combs(window, Y_honeycombSprite, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, current_R_bees);

        Drawing_Red_Combs(window, R_honeycombSprite, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count);

        Drawing_random_Combs(window, rand_combSprite, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs);


        KillerBeesManager(window, KillerBeeNext, Kill_bees_count, max_Kill_bees, K_bee_exist, KillerBeeSprite, K_bee_x, K_bee_y, K_beeDirection, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist);

        humminbirdManager(window, Bird, BirdMove, BirdSprite, bird_x, bird_y, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, current_R_bees, SickStatus, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count, score, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs);

        RegularBeesManager(window, regularBeeNext, current_R_bees, max_R_bees, R_bee_exist, regularBeeSprite, R_bee_x, R_bee_y, beeDirection, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, BeeStay, Hive_x, Hive_y, BeeHive_exist, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs, R_bees_animation, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count);

        obstaclesManager(window, obstacleSprite, R_bee_x, R_bee_y, current_R_bees, R_bee_exist, obstacleX, obstacleY, obsatclesCounter, player_x, K_bee_x, K_bee_y, K_bee_exist, space, Left, Right, Kill_bees_count);


        DrawingHives(window, HiveSprite, Hive_x, Hive_y, BeeHive_exist, current_R_bees);



        if (bullet_exists == true) {
            moveBullet(bullet_y, bullet_exists, bulletClock, bgMusic);
            drawBullet(window, bullet_x, bullet_y, bulletSprite);
        }
        else {
            bullet_x = player_x;
            bullet_y = player_y;
        }

        magazine.setPosition(player_x + 15, player_y + boxPixelsY);
        window.draw(magazine);
        drawPlayer(window, player_x, player_y, playerSprite);
        window.draw(groundRectangle);

        for (int i = 1; i < remainingLives; i++) {
            lifeSprite.setPosition(i * 50, resolutionY - boxPixelsX * 2);
            window.draw(lifeSprite);
        }

        scoreText.setString("Score: " + to_string(score));
        scoreText.setPosition(resolutionX - boxPixelsX * 7 - 10, resolutionY - boxPixelsY - 20);
        window.draw(scoreText);

        window.display();
        window.clear();
    }

}














void Level_Three(RenderWindow& window, bool& inLevel3, int& remainingLives, unsigned int& score, int& nextdicision, int& beehivescores) {

    Music bgMusic;
    if (!bgMusic.openFromFile("Music/risk.ogg")) {
        cout << "Error: Could not load music file!" << endl;
    }
    bgMusic.setVolume(50);
    bgMusic.setLoop(true);
    bgMusic.play();

    Music fireSound;
    if (!fireSound.openFromFile("Sound Effects/fire.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    fireSound.setVolume(150);

    Music hitSound;
    if (!hitSound.openFromFile("Sound Effects/hit.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    hitSound.setVolume(100);


    // Initializing Player and Player Sprites.
    float player_x = (gameRows / 2) * boxPixelsX;
    float player_y = (gameColumns - 4) * boxPixelsY;

    Texture playerTexture;
    Sprite playerSprite;
    playerTexture.loadFromFile("Textures/spray.png");
    playerSprite.setTexture(playerTexture);
    Clock player_movClock;
    playerSprite.setTextureRect(IntRect(0, 0, boxPixelsX + 100, boxPixelsY + 100));


    float bullet_x = player_x;
    float bullet_y = player_y;
    bool bullet_exists = false;
    bool spacePressed = false;


    Clock bulletClock;
    Texture bulletTexture;
    Sprite bulletSprite;
    bulletTexture.loadFromFile("Textures/bullet.png");
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setScale(2, 2);
    bulletSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));





    const int max_R_bees = 20;
    Clock regularBeeNext;
    Texture regularBeeTexture;
    regularBeeTexture.loadFromFile("Sprites/BeeSheet.png");
    Sprite regularBeeSprite[max_R_bees];

    int current_R_bees = 0;
    float R_bee_x[max_R_bees];
    float R_bee_y[max_R_bees];
    bool R_bee_exist[max_R_bees];
    int beeDirection[max_R_bees];
    for (int i = 0; i < max_R_bees; i++)
    {

        regularBeeSprite[i].setTexture(regularBeeTexture);
        R_bee_exist[i] = false;

        if (i & 1)
        {
            R_bee_x[i] = 0;
            R_bee_y[i] = boxPixelsY;
            beeDirection[i] = 1;
            regularBeeSprite[i].setScale(-1.8, 1.8);
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));
        }
        else {
            R_bee_x[i] = resolutionX;
            R_bee_y[i] = boxPixelsY;
            beeDirection[i] = -1;
            regularBeeSprite[i].setScale(1.8, 1.8);
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));
        }
    }







    const int max_Kill_bees = 10;
    Clock KillerBeeNext;
    Texture KillerBeeTexture;
    KillerBeeTexture.loadFromFile("Textures/Regular_bee.png");
    Sprite KillerBeeSprite[max_Kill_bees];

    int Kill_bees_count = 0;
    float K_bee_x[max_Kill_bees];
    float K_bee_y[max_Kill_bees];
    bool K_bee_exist[max_Kill_bees];
    int K_beeDirection[max_Kill_bees];
    for (int i = 0; i < max_Kill_bees; i++)
    {
        KillerBeeSprite[i].setTexture(KillerBeeTexture);
        K_bee_exist[i] = false;
        if (i & 1) {
            K_bee_x[i] = 0;
            K_bee_y[i] = boxPixelsY;
            K_beeDirection[i] = 1;
            KillerBeeSprite[i].setScale(-1.2, 1.2);
        }
        else {
            K_bee_x[i] = resolutionX;
            K_bee_y[i] = boxPixelsY;
            K_beeDirection[i] = -1;
            KillerBeeSprite[i].setScale(1.2, 1.2);
        }
    }


    Texture Y_honeycombTextute;
    Y_honeycombTextute.loadFromFile("Textures/honeycomb.png");
    Sprite Y_honeycombSprite[max_R_bees];
    bool Y_honeycomb_exist[max_R_bees];
    float Y_honeycomb_x[max_R_bees];
    float Y_honeycomb_y[max_R_bees];
    Clock BeeStay[max_R_bees];

    for (int i = 0; i < max_R_bees; i++)
    {
        Y_honeycombSprite[i].setTexture(Y_honeycombTextute);
        Y_honeycombSprite[i].setScale(0.8f, 0.8f);
        Y_honeycombSprite[i].setOrigin(15, 1);
        Y_honeycomb_x[i] = -64;
        Y_honeycomb_y[i] = -64;
        Y_honeycomb_exist[i] = false;
    }

    Texture R_honeycombTextute;
    R_honeycombTextute.loadFromFile("Textures/honeycomb_red.png");
    Sprite R_honeycombSprite[max_Kill_bees];
    bool R_honeycomb_exist[max_Kill_bees];
    float R_honeycomb_x[max_Kill_bees];
    float R_honeycomb_y[max_Kill_bees];
    Clock R_bees_animation;


    for (int i = 0; i < max_Kill_bees; i++)
    {
        R_honeycombSprite[i].setTexture(R_honeycombTextute);
        R_honeycombSprite[i].setScale(0.8f, 0.8f);
        R_honeycombSprite[i].setOrigin(15, 1);
        R_honeycomb_exist[i] = false;
    }

    const int rand_combs = 15;
    Sprite rand_combSprite[rand_combs];
    bool rand_comb_exist[rand_combs];
    float rand_comb_x[rand_combs];
    float rand_comb_y[rand_combs];

    for (int i = 0; i < rand_combs; i++)
    {
        rand_combSprite[i].setTexture(Y_honeycombTextute);
        rand_combSprite[i].setScale(0.8f, 0.8f);
        rand_combSprite[i].setOrigin(15, 1);
        rand_comb_x[i] = rand() % (resolutionX - boxPixelsX) + 10;
        rand_comb_y[i] = rand() % 460 + boxPixelsY;
        rand_comb_exist[i] = true;
    }

    Texture obstacleTexture;
    obstacleTexture.loadFromFile("Textures/obstacles.png");
    Sprite obstacleSprite[gameRows * 2];
    float obstacleY[gameRows * 2] = { 0 };
    float obstacleX[gameRows * 2] = { 0 };
    for (int i = 0; i < gameRows * 2; i++)
    {
        obstacleX[i] = -32;
        obstacleSprite[i].setTexture(obstacleTexture);
    }
    int obsatclesCounter = 0;
    int space = 1;
    int Left = 0;
    int Right = 1;

    Texture BirdTexture;
    BirdTexture.loadFromFile("Textures/bird.png");
    Sprite BirdSprite;
    BirdSprite.setTexture(BirdTexture);
    Music BirdhitSound;
    if (!BirdhitSound.openFromFile("Sound Effects/birdHit.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    BirdSprite.setScale(2.6, 2.5);
    BirdSprite.setColor(Color::Red);
    float bird_x = resolutionX - boxPixelsX;
    float bird_y = boxPixelsY;
    Clock Bird;
    Clock BirdMove;
    Clock SickTime;
    bool SickStatus = true;
    BirdMove.restart();


    Texture HivesTexture;
    HivesTexture.loadFromFile("Textures/hive.png");
    Sprite HiveSprite[max_R_bees];
    bool BeeHive_exist[max_R_bees];
    float Hive_x[max_R_bees];
    float Hive_y[max_R_bees];
    for (int i = 0; i < max_R_bees; i++)
    {
        Hive_x[i] = 0;
        Hive_y[i] = 0;
        BeeHive_exist[i] = false;
        HiveSprite[i].setTexture(HivesTexture);

    }

    Texture BackgroungL1;
    BackgroungL1.loadFromFile("Textures/background_L1.jpg");
    Sprite BG_L1;
    BG_L1.setTexture(BackgroungL1);
    BG_L1.setScale(1.4, 1.5);


    RectangleShape groundRectangle(Vector2f(960, 64));
    groundRectangle.setPosition(0, (gameColumns - 2) * boxPixelsY);
    groundRectangle.setFillColor(Color::Green);




    Font font;
    if (!font.loadFromFile("Fonts/Jaro.ttf")) {
        cout << "Error: Could not load font file!" << endl;

    }

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(35);
    scoreText.setFillColor(Color::White);
    scoreText.setStyle(Text::Bold);
    scoreText.setOutlineColor(Color::Black);
    scoreText.setOutlineThickness(2.0f);


    const int maxFires = 64;
    int remainingFires = maxFires;
    int firedBullets = 0;
    int magazineBlock = 1;

    RectangleShape magazine(Vector2f(boxPixelsY, boxPixelsY));
    magazine.setFillColor(Color::Yellow);



    Texture lifeTexture;
    Sprite lifeSprite;
    lifeTexture.loadFromFile("Textures/spray.png");
    lifeSprite.setTexture(lifeTexture);
    lifeSprite.setColor(Color::Black);



    Clock Nextlevel;
    Clock Nextlevelwait;


    bool hivescorevalidator = true;
    while (inLevel3) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                bgMusic.stop();
                inLevel3 = false;
                return;
                window.close();

            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape || remainingLives == 0 || nextdicision == 3) {
                inLevel3 = false;

                bgMusic.stop();
                // levelSetup=0;
            }
        }


        bool allBeesDead = true;


        for (int i = 0; i < max_R_bees; i++) {
            if (Nextlevel.getElapsedTime() >= seconds(2)) {
                if (R_bee_exist[i]) {
                    allBeesDead = false;
                    Nextlevelwait.restart();
                    break;
                }
            }
        }


        if (allBeesDead) {
            for (int i = 0; i < max_Kill_bees; i++) {
                if (Nextlevel.getElapsedTime() >= seconds(2)) {
                    if (K_bee_exist[i]) {
                        allBeesDead = false;
                        Nextlevelwait.restart();
                        break;
                    }
                }
            }
        }


        if (allBeesDead) {
            if (Nextlevelwait.getElapsedTime() >= seconds(7)) {
                nextdicision = 3;
                if (hivescorevalidator)
                    for (int i = 0; i < max_R_bees; i++)
                        if (BeeHive_exist[i])
                            beehivescores++;
                hivescorevalidator = false;

            }

        }



        window.draw(BG_L1);

        MovePlayer(player_x, player_movClock, obstacleX, obstacleY, remainingLives);

        Firing(bullet_exists, bullet_x, bullet_y, player_x, player_y, spacePressed, fireSound, bgMusic, remainingFires, firedBullets, remainingLives, magazine, magazineBlock);

        updateGrid(player_x, player_y, bullet_x, bullet_y, R_bee_x, R_bee_y, R_bee_exist, current_R_bees, Y_honeycomb_x, Y_honeycomb_y, K_bee_x, K_bee_y, K_bee_exist, Kill_bees_count, R_honeycomb_x, R_honeycomb_y, bullet_exists, bgMusic, hitSound, Y_honeycomb_exist, R_honeycomb_exist, Hive_x, Hive_y, BeeHive_exist, rand_comb_x, rand_comb_y, rand_comb_exist, score, rand_combs);

        HummingBird_Health(bullet_x, bullet_y, bird_x, bird_y, SickStatus, bullet_exists, BirdSprite, SickTime, BirdhitSound, bgMusic);

        Drawing_Yellow_Combs(window, Y_honeycombSprite, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, current_R_bees);

        Drawing_Red_Combs(window, R_honeycombSprite, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count);

        Drawing_random_Combs(window, rand_combSprite, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs);


        KillerBeesManager(window, KillerBeeNext, Kill_bees_count, max_Kill_bees, K_bee_exist, KillerBeeSprite, K_bee_x, K_bee_y, K_beeDirection, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist);

        humminbirdManager(window, Bird, BirdMove, BirdSprite, bird_x, bird_y, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, current_R_bees, SickStatus, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count, score, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs);

        RegularBeesManager(window, regularBeeNext, current_R_bees, max_R_bees, R_bee_exist, regularBeeSprite, R_bee_x, R_bee_y, beeDirection, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, BeeStay, Hive_x, Hive_y, BeeHive_exist, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs, R_bees_animation, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count);

        obstaclesManager(window, obstacleSprite, R_bee_x, R_bee_y, current_R_bees, R_bee_exist, obstacleX, obstacleY, obsatclesCounter, player_x, K_bee_x, K_bee_y, K_bee_exist, space, Left, Right, Kill_bees_count);


        DrawingHives(window, HiveSprite, Hive_x, Hive_y, BeeHive_exist, current_R_bees);



        if (bullet_exists == true) {
            moveBullet(bullet_y, bullet_exists, bulletClock, bgMusic);
            drawBullet(window, bullet_x, bullet_y, bulletSprite);
        }
        else {
            bullet_x = player_x;
            bullet_y = player_y;
        }

        magazine.setPosition(player_x + 15, player_y + boxPixelsY);
        window.draw(magazine);
        drawPlayer(window, player_x, player_y, playerSprite);
        window.draw(groundRectangle);

        for (int i = 1; i < remainingLives; i++) {
            lifeSprite.setPosition(i * 50, resolutionY - boxPixelsX * 2);
            window.draw(lifeSprite);
        }

        scoreText.setString("Score: " + to_string(score));
        scoreText.setPosition(resolutionX - boxPixelsX * 7 - 10, resolutionY - boxPixelsY - 20);
        window.draw(scoreText);

        window.display();
        window.clear();
    }

}







void Boss_Level(RenderWindow& window, bool& inLevel4, int& remainingLives, unsigned int& score, int& nextdicision, int& beehivescores) {

    Music bgMusic;
    if (!bgMusic.openFromFile("Music/magical_journey.ogg")) {
        cout << "Error: Could not load music file!" << endl;
    }
    bgMusic.setVolume(50);
    bgMusic.setLoop(true);
    bgMusic.play();

    Music fireSound;
    if (!fireSound.openFromFile("Sound Effects/fire.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    fireSound.setVolume(150);

    Music hitSound;
    if (!hitSound.openFromFile("Sound Effects/hit.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    hitSound.setVolume(100);


    // Initializing Player and Player Sprites.
    float player_x = (gameRows / 2) * boxPixelsX;
    float player_y = (gameColumns - 4) * boxPixelsY;

    Texture playerTexture;
    Sprite playerSprite;
    playerTexture.loadFromFile("Textures/spray.png");
    playerSprite.setTexture(playerTexture);
    Clock player_movClock;
    playerSprite.setTextureRect(IntRect(0, 0, boxPixelsX + 100, boxPixelsY + 100));


    float bullet_x = player_x;
    float bullet_y = player_y;
    bool bullet_exists = false;
    bool spacePressed = false;


    Clock bulletClock;
    Texture bulletTexture;
    Sprite bulletSprite;
    bulletTexture.loadFromFile("Textures/bullet.png");
    bulletSprite.setTexture(bulletTexture);
    bulletSprite.setScale(2, 2);
    bulletSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));





    const int max_R_bees = 20;
    Clock regularBeeNext;
    Texture regularBeeTexture;
    regularBeeTexture.loadFromFile("Sprites/BeeSheet.png");
    Sprite regularBeeSprite[max_R_bees];

    int current_R_bees = 0;
    float R_bee_x[max_R_bees];
    float R_bee_y[max_R_bees];
    bool R_bee_exist[max_R_bees];
    int beeDirection[max_R_bees];
    for (int i = 0; i < max_R_bees; i++)
    {

        regularBeeSprite[i].setTexture(regularBeeTexture);
        R_bee_exist[i] = false;
        // regularBeeSprite[i].setPosition(0.f, boxPixelsY);
        if (i & 1)
        {
            R_bee_x[i] = 0;
            R_bee_y[i] = boxPixelsY;
            beeDirection[i] = 1;
            regularBeeSprite[i].setScale(-1.8, 1.8);
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));
        }
        else {
            R_bee_x[i] = resolutionX;
            R_bee_y[i] = boxPixelsY;
            beeDirection[i] = -1;
            regularBeeSprite[i].setScale(1.8, 1.8);
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));
        }
    }







    const int max_Kill_bees = 15;
    Clock KillerBeeNext;
    Texture KillerBeeTexture;
    KillerBeeTexture.loadFromFile("Textures/Regular_bee.png");
    Sprite KillerBeeSprite[max_Kill_bees];

    int Kill_bees_count = 0;
    float K_bee_x[max_Kill_bees];
    float K_bee_y[max_Kill_bees];
    bool K_bee_exist[max_Kill_bees];
    int K_beeDirection[max_Kill_bees];
    for (int i = 0; i < max_Kill_bees; i++)
    {
        KillerBeeSprite[i].setTexture(KillerBeeTexture);
        K_bee_exist[i] = false;
        if (i & 1) {
            K_bee_x[i] = 0;
            K_bee_y[i] = boxPixelsY;
            K_beeDirection[i] = 1;
            KillerBeeSprite[i].setScale(-1.2, 1.2);
        }
        else {
            K_bee_x[i] = resolutionX;
            K_bee_y[i] = boxPixelsY;
            K_beeDirection[i] = -1;
            KillerBeeSprite[i].setScale(1.2, 1.2);
        }
    }


    Texture Y_honeycombTextute;
    Y_honeycombTextute.loadFromFile("Textures/honeycomb.png");
    Sprite Y_honeycombSprite[max_R_bees];
    bool Y_honeycomb_exist[max_R_bees];
    float Y_honeycomb_x[max_R_bees];
    float Y_honeycomb_y[max_R_bees];
    Clock BeeStay[max_R_bees];

    for (int i = 0; i < max_R_bees; i++)
    {
        Y_honeycombSprite[i].setTexture(Y_honeycombTextute);
        Y_honeycombSprite[i].setScale(0.8f, 0.8f);
        Y_honeycombSprite[i].setOrigin(15, 1);
        Y_honeycomb_x[i] = -64;
        Y_honeycomb_y[i] = -64;
        Y_honeycomb_exist[i] = false;
    }

    Texture R_honeycombTextute;
    R_honeycombTextute.loadFromFile("Textures/honeycomb_red.png");
    Sprite R_honeycombSprite[max_Kill_bees];
    bool R_honeycomb_exist[max_Kill_bees];
    float R_honeycomb_x[max_Kill_bees];
    float R_honeycomb_y[max_Kill_bees];
    Clock R_bees_animation;


    for (int i = 0; i < max_Kill_bees; i++)
    {
        R_honeycombSprite[i].setTexture(R_honeycombTextute);
        R_honeycombSprite[i].setScale(0.8f, 0.8f);
        R_honeycombSprite[i].setOrigin(15, 1);
        R_honeycomb_exist[i] = false;
    }

    const int rand_combs = 15;
    Sprite rand_combSprite[rand_combs];
    bool rand_comb_exist[rand_combs];
    float rand_comb_x[rand_combs];
    float rand_comb_y[rand_combs];

    for (int i = 0; i < rand_combs; i++)
    {
        rand_combSprite[i].setTexture(Y_honeycombTextute);
        rand_combSprite[i].setScale(0.8f, 0.8f);
        rand_combSprite[i].setOrigin(15, 1);
        rand_comb_x[i] = rand() % (resolutionX - boxPixelsX) + 10;
        rand_comb_y[i] = rand() % 460 + boxPixelsY;
        rand_comb_exist[i] = true;
    }

    Texture obstacleTexture;
    obstacleTexture.loadFromFile("Textures/obstacles.png");
    Sprite obstacleSprite[gameRows * 2];
    float obstacleY[gameRows * 2] = { 0 };
    float obstacleX[gameRows * 2] = { 0 };
    for (int i = 0; i < gameRows * 2; i++)
    {
        obstacleX[i] = -32;
        obstacleSprite[i].setTexture(obstacleTexture);
    }
    int obsatclesCounter = 0;
    int space = 1;
    int Left = 0;
    int Right = 1;

    Texture BirdTexture;
    BirdTexture.loadFromFile("Textures/bird.png");
    Sprite BirdSprite;
    BirdSprite.setTexture(BirdTexture);
    Music BirdhitSound;
    if (!BirdhitSound.openFromFile("Sound Effects/birdHit.wav")) {
        cout << "Error: Could not load music file!" << endl;
    }
    BirdSprite.setScale(2.6, 2.5);
    BirdSprite.setColor(Color::Red);
    float bird_x = resolutionX - boxPixelsX;
    float bird_y = boxPixelsY;
    Clock Bird;
    Clock BirdMove;
    Clock SickTime;
    bool SickStatus = true;
    BirdMove.restart();


    Texture HivesTexture;
    HivesTexture.loadFromFile("Textures/hive.png");
    Sprite HiveSprite[max_R_bees];
    bool BeeHive_exist[max_R_bees];
    float Hive_x[max_R_bees];
    float Hive_y[max_R_bees];
    for (int i = 0; i < max_R_bees; i++)
    {
        if (i < 5) {
            BeeHive_exist[i] = true;
            Hive_x[i] = rand() % (resolutionX - boxPixelsX) + 10;
            Hive_y[i] = rand() % 460 + boxPixelsY;
        }
        else
            BeeHive_exist[i] = false;
        HiveSprite[i].setTexture(HivesTexture);
        HiveSprite[i].setOrigin(boxPixelsX / 2, boxPixelsY / 2);
    }

    Texture BackgroungL1;
    BackgroungL1.loadFromFile("Textures/background_L1.jpg");
    Sprite BG_L1;
    BG_L1.setTexture(BackgroungL1);
    BG_L1.setScale(1.4, 1.5);


    RectangleShape groundRectangle(Vector2f(960, 64));
    groundRectangle.setPosition(0, (gameColumns - 2) * boxPixelsY);
    groundRectangle.setFillColor(Color::Green);




    Font font;
    if (!font.loadFromFile("Fonts/Jaro.ttf")) {
        cout << "Error: Could not load font file!" << endl;

    }

    Text scoreText;
    scoreText.setFont(font);
    scoreText.setCharacterSize(35);
    scoreText.setFillColor(Color::White);
    scoreText.setStyle(Text::Bold);
    scoreText.setOutlineColor(Color::Black); // Set the border color
    scoreText.setOutlineThickness(2.0f);


    const int maxFires = 64;
    int remainingFires = maxFires;
    int firedBullets = 0;
    int magazineBlock = 1;

    RectangleShape magazine(Vector2f(boxPixelsY, boxPixelsY));
    magazine.setFillColor(Color::Yellow);



    Texture lifeTexture;
    Sprite lifeSprite;
    lifeTexture.loadFromFile("Textures/spray.png");
    lifeSprite.setTexture(lifeTexture);
    lifeSprite.setColor(Color::Black);



    Clock Nextlevel;
    Clock Nextlevelwait;

    ////////////////////////////////////////////////////////////////////////////// 
    bool Boss_Status = true;
    Texture Speed_Inc;
    Speed_Inc.loadFromFile("Sprites/Speed_Inc.png");
    Texture Speed_Dec;
    Speed_Dec.loadFromFile("Sprites/Speed_Dec.png");
    Texture Height_Inc;
    Height_Inc.loadFromFile("Sprites/Height_Inc.png");
    Texture Height_Dec;
    Height_Dec.loadFromFile("Sprites/Height_Dec.png");
    Sprite PowerUpSprite[max_R_bees * 3];

    float power_up_x[max_R_bees * 3];
    float power_up_y[max_R_bees * 3];
    bool powerUp_exist[max_R_bees * 3] = { false };
    Clock powerUpVisible[max_R_bees * 3];

    int powerup_count = 0;




    bool hivescorevalidator = true;

    while (inLevel4) {

        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                bgMusic.stop();
                inLevel4 = false;
                return;
                window.close();

            }
            if (event.type == Event::KeyPressed && event.key.code == Keyboard::Escape || remainingLives == 0 || nextdicision == 4) {
                inLevel4 = false;


                bgMusic.stop();

                // levelSetup=0;
            }
        }


        bool allBeesDead = true;


        for (int i = 0; i < max_R_bees; i++) {
            if (Nextlevel.getElapsedTime() >= seconds(2)) {
                if (R_bee_exist[i]) {
                    allBeesDead = false;
                    Nextlevelwait.restart();
                    break;
                }
            }
        }


        if (allBeesDead) {
            for (int i = 0; i < max_Kill_bees; i++) {
                if (Nextlevel.getElapsedTime() >= seconds(2)) {
                    if (K_bee_exist[i]) {
                        allBeesDead = false;
                        Nextlevelwait.restart();
                        break;
                    }
                }
            }
        }


        if (allBeesDead) {
            if (Nextlevelwait.getElapsedTime() >= seconds(7)) {
                nextdicision = 4;
                if (hivescorevalidator)
                    for (int i = 0; i < max_R_bees; i++)
                        if (BeeHive_exist[i])
                            beehivescores++;
                hivescorevalidator = false;

            }

        }



        window.draw(BG_L1);



        Firing(bullet_exists, bullet_x, bullet_y, player_x, player_y, spacePressed, fireSound, bgMusic, remainingFires, firedBullets, remainingLives, magazine, magazineBlock);


        updateGrid(player_x, player_y, bullet_x, bullet_y, R_bee_x, R_bee_y, R_bee_exist, current_R_bees, Y_honeycomb_x, Y_honeycomb_y, K_bee_x, K_bee_y, K_bee_exist, Kill_bees_count, R_honeycomb_x, R_honeycomb_y, bullet_exists, bgMusic, hitSound, Y_honeycomb_exist, R_honeycomb_exist, Hive_x, Hive_y, BeeHive_exist, rand_comb_x, rand_comb_y, rand_comb_exist, score, rand_combs);

        HummingBird_Health(bullet_x, bullet_y, bird_x, bird_y, SickStatus, bullet_exists, BirdSprite, SickTime, BirdhitSound, bgMusic);

        Drawing_Yellow_Combs(window, Y_honeycombSprite, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, current_R_bees);

        Drawing_Red_Combs(window, R_honeycombSprite, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count);

        Drawing_random_Combs(window, rand_combSprite, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs);


        KillerBeesManager(window, KillerBeeNext, Kill_bees_count, max_Kill_bees, K_bee_exist, KillerBeeSprite, K_bee_x, K_bee_y, K_beeDirection, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist);

        humminbirdManager(window, Bird, BirdMove, BirdSprite, bird_x, bird_y, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, current_R_bees, SickStatus, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count, score, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs, power_up_x, power_up_y, powerUp_exist, powerup_count, powerUpVisible);

        RegularBeesManager(window, regularBeeNext, current_R_bees, max_R_bees, R_bee_exist, regularBeeSprite, R_bee_x, R_bee_y, beeDirection, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, BeeStay, Hive_x, Hive_y, BeeHive_exist, rand_comb_x, rand_comb_y, rand_comb_exist, rand_combs, R_bees_animation, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count);

        obstaclesManager(window, obstacleSprite, R_bee_x, R_bee_y, current_R_bees, R_bee_exist, obstacleX, obstacleY, obsatclesCounter, player_x, K_bee_x, K_bee_y, K_bee_exist, space, Left, Right, Kill_bees_count);


        DrawingHives(window, HiveSprite, Hive_x, Hive_y, BeeHive_exist, max_R_bees);



        if (bullet_exists == true) {
            moveBullet(bullet_y, bullet_exists, bulletClock, bgMusic);
            drawBullet(window, bullet_x, bullet_y, bulletSprite);
        }
        else {
            bullet_x = player_x + 30;
            bullet_y = player_y;
        }

        magazine.setPosition(player_x + 15, player_y + boxPixelsY);
        window.draw(magazine);
        drawPlayer(window, player_x, player_y, playerSprite);
        window.draw(groundRectangle);

        spawnPowerUps(Speed_Inc, Speed_Dec, Height_Inc, Height_Dec, PowerUpSprite, power_up_x, power_up_y, powerUp_exist, powerup_count, window, powerUpVisible, bullet_x, bullet_y, bullet_exists, R_honeycomb_x, R_honeycomb_y, R_honeycomb_exist, Kill_bees_count, player_x, player_y, obstacleX, playerSprite, remainingLives);

        for (int i = 1; i < remainingLives; i++) {
            lifeSprite.setPosition(i * 50, resolutionY - boxPixelsX * 2);
            window.draw(lifeSprite);
        }

        scoreText.setString("Score: " + to_string(score));
        scoreText.setPosition(resolutionX - boxPixelsX * 7 - 10, resolutionY - boxPixelsY - 20);
        window.draw(scoreText);

        window.display();
        window.clear();
    }

}







RectangleShape speedTimerBar;
RectangleShape heightTimerBar;







void spawnPowerUps(Texture& Speed_Inc, Texture& Speed_Dec, Texture& Height_Inc, Texture& Height_Dec, Sprite PowerUpSprite[], float power_up_x[], float power_up_y[], bool powerUp_exist[], int& powerup_count, RenderWindow& window, Clock powerUpVisible[], float bullet_x, float bullet_y, bool& bullet_exists, float R_honeycomb_x[], float R_honeycomb_y[], bool R_honeycomb_exist[], int k_beeCount, float& player_x, float& player_y, float obstacleX[], Sprite& playerSprite, int& remainingLives) {
    static bool decheight = false;
    static bool incheight = false;
    static bool decspeed = false;
    static bool incspeed = false;
    static bool heightTimerActive = false;
    static bool speedTimerActive = false;
    static Clock speedTimer;
    static Clock heightTimer;
    static float speed = 0.5;

    int bulletGridX = bullet_x / boxPixelsX;
    int bulletGridY = bullet_y / boxPixelsY;


    for (int i = 0; i < k_beeCount; i++) {
        if (R_honeycomb_exist[i]) {
            int RcombGridX = R_honeycomb_x[i] / boxPixelsX;
            int RcombGridY = R_honeycomb_y[i] / boxPixelsY;

            if (RcombGridX == bulletGridX && RcombGridY == bulletGridY && bulletGridY < 16) {
                bullet_exists = false;
                R_honeycomb_exist[i] = false;
                power_up_x[powerup_count] = R_honeycomb_x[i];
                power_up_y[powerup_count] = R_honeycomb_y[i];
                powerUp_exist[powerup_count] = true;
                powerUpVisible[powerup_count].restart();

                R_honeycomb_x[i] = -64;
                R_honeycomb_y[i] = -64;
                powerup_count++;
            }
        }
    }

    // Draw power-ups
    for (int i = 0; i < powerup_count; i++) {
        if (i % 4 == 0)
            PowerUpSprite[i].setTexture(Height_Inc);
        else if (i % 4 == 1)
            PowerUpSprite[i].setTexture(Height_Dec);
        else if (i % 4 == 2)
            PowerUpSprite[i].setTexture(Speed_Dec);
        else if (i % 4 == 3)
            PowerUpSprite[i].setTexture(Speed_Inc);

        if (powerUp_exist[i]) {
            PowerUpSprite[i].setPosition(power_up_x[i], power_up_y[i]);
            window.draw(PowerUpSprite[i]);
            if (power_up_y[i] <= resolutionY - boxPixelsY * 3)
                power_up_y[i] += 0.2;
        }
    }


    int playerGridX = player_x / boxPixelsX;
    int playerGridY = player_y / boxPixelsY;

    for (int i = 0; i < powerup_count; i++) {
        if (powerUp_exist[i]) {
            int powerGridX = power_up_x[i] / boxPixelsX;
            int powerGridY = power_up_y[i] / boxPixelsY;

            if (playerGridX == powerGridX && playerGridY + 1 == powerGridY) {

                if (i % 4 == 0) { // Height Decrease
                    if (incheight) {
                        incheight = false;
                        playerSprite.setScale(1, 1);
                        decheight = false;
                        heightTimerActive = false;
                    }
                    else {
                        decheight = true;
                        playerSprite.setScale(1, 0.5);
                        heightTimer.restart();
                        heightTimerActive = true;
                    }
                }
                else if (i % 4 == 1) { // Height Increase
                    if (decheight) {
                        decheight = false;
                        incheight = false;
                        playerSprite.setScale(1, 1);
                        heightTimerActive = false;
                    }
                    else {
                        incheight = true;
                        playerSprite.setScale(1, 2);
                        heightTimer.restart();
                        heightTimerActive = true;
                    }
                }
                else if (i % 4 == 2) { // Speed Decrease
                    if (incspeed) {
                        incspeed = false;
                        decspeed = false;
                        speed = 0.5;
                        speedTimerActive = false;
                    }
                    else {
                        decspeed = true;
                        speed = 0.1;
                        speedTimer.restart();
                        speedTimerActive = true;
                    }
                }
                else if (i % 4 == 3) { // Speed Increase
                    if (decspeed) {
                        decspeed = false;
                        speed = 0.5;
                        incspeed = false;
                        speedTimerActive = false;
                    }
                    else {
                        incspeed = true;
                        speedTimer.restart();
                        speed = 1;
                        speedTimerActive = true;
                    }
                }

                powerUp_exist[i] = false;
            }
        }
    }


    if (heightTimerActive) {
        float HeightTime = heightTimer.getElapsedTime().asSeconds();
        if (HeightTime >= 10) {

            heightTimerActive = false;
            decheight = incheight = false;

            playerSprite.setScale(1, 1);
        }
        else {

            float remainingHeightTime = 10 - HeightTime;

            heightTimerBar.setSize(Vector2f(remainingHeightTime * 20, 10));
            heightTimerBar.setFillColor(Color::Blue);

            heightTimerBar.setPosition(resolutionX / 2 - boxPixelsX * 2, resolutionY - 40);
            window.draw(heightTimerBar);
        }
    }


    if (speedTimerActive) {
        float SpeedTime = speedTimer.getElapsedTime().asSeconds();
        if (SpeedTime >= 10) {
            speedTimerActive = false;
            decspeed = incspeed = false;
            speed = 0.5;
        }
        else {

            float remainingSpeedTime = 10 - SpeedTime;

            speedTimerBar.setSize(Vector2f(remainingSpeedTime * 20, 10));
            speedTimerBar.setFillColor(Color::Red);
            speedTimerBar.setPosition(resolutionX / 2 - boxPixelsX * 2, resolutionY - 20);
            window.draw(speedTimerBar);
        }
    }

    for (int i = 0; i < powerup_count; i++)
    {
        if (powerUp_exist[i] && powerUpVisible[i].getElapsedTime() >= seconds(7)) {
            powerUp_exist[i] = false;
        }
    }


    for (int i = 0; i < gameRows; i++)
    {
        int obstacleGridX = obstacleX[i] / boxPixelsX;
        if (playerGridX == obstacleGridX)
            player_x += 1;
        if (playerGridX + 2 == obstacleGridX)
            player_x -= 1;
        if (playerGridX == obstacleGridX)
            for (int j = 0; j < gameRows; j++)
            {
                int obstacleGridX = obstacleX[j] / boxPixelsX;
                if (playerGridX + 2 == obstacleGridX)
                    remainingLives = 0;
            }


    }






    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        player_x -= speed;
        if (player_x < 0)
            player_x = 0;



    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        player_x += speed;
        if (player_x > resolutionX - (boxPixelsX * 2))
            player_x = resolutionX - (boxPixelsX * 2);

    }


}








////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Write your functions definitions here. Some have been written for you. //
//                                                                        //
////////////////////////////////////////////////////////////////////////////



// void spawnPowerUps(RenderWindow& window, Texture& Speed_Inc, Texture& Speed_Dec, Texture& Height_Inc, Texture& Height_Dec,Sprite PowerUpSprite[], float power_up_x[], float power_up_y[], bool powerUp_exist[],int& powerup_count, RenderWindow& window, Clock powerUpVisible[], float bullet_x, float bullet_y,bool& bullet_exists,float R_honeycomb_x[],float R_honeycomb_y[],bool R_honeycomb_exist[],int k_beeCount,float& player_x,float& player_y,float obstacleX[]){

// 			static bool decheight=false;
// 			static bool incheight=false;
// 			static bool decspeed=false;
// 			static bool incspeed=false;

//             int bulletGridX = bullet_x / boxPixelsX;
//             int bulletGridY = bullet_y / boxPixelsY;  


//             for (int i = 0; i < k_beeCount; i++) {
//         if (R_honeycomb_exist[i]){ 

//             int RcombGridX = R_honeycomb_x[i] / boxPixelsX;
//             int RcombGridY = R_honeycomb_y[i] / boxPixelsY;


//             if (RcombGridX==bulletGridX && RcombGridY==bulletGridY && bulletGridY<16){
//                 bullet_exists=false;
// 			R_honeycomb_exist[i]=false;
//             power_up_x[powerup_count]= R_honeycomb_x[i];
// 			power_up_y[powerup_count]=R_honeycomb_y[i];
//             powerUp_exist[powerup_count]=true;
// 			powerUpVisible[powerup_count].restart();


// 			R_honeycomb_x[i]=-64;
// 			R_honeycomb_y[i]=-64;
//             powerup_count++;

//             }			
// 		}	        
//     } 


//     for (int i = 0; i < powerup_count; i++)
//     {
// 		 if(i%4==0)
//                 PowerUpSprite[i].setTexture(Height_Dec);
//             else if(i%4==1)
//                 PowerUpSprite[i].setTexture(Height_Inc);
//             else if(i%4==2)
//                 PowerUpSprite[i].setTexture(Speed_Dec);
//             else if(i%4==3)
//                 PowerUpSprite[i].setTexture(Speed_Inc);

//         if(powerUp_exist[i]){
//             PowerUpSprite[i].setPosition(power_up_x[i],power_up_y[i]);
//             window.draw(PowerUpSprite[i]);
//             if(power_up_y[i]<=resolutionY-boxPixelsY*3)
//             power_up_y[i]+=0.2;


//         }
//     }


// 	int playerGridX=player_x/boxPixelsX;
// 	int playerGridY=player_y/boxPixelsY;

// 				for (int i = 0; i < gameRows; i++)
// 				{
// 	                int obstacleGridX= obstacleX[i] / boxPixelsX;
// 					if(playerGridX== obstacleGridX)
// 					player_x+=1;
// 					if(playerGridX+2 == obstacleGridX)
// 					player_x-=1;
//                     if (playerGridX == obstacleGridX)
//                     for (int j = 0; j < gameRows; j++)
//                     {
//                         int obstacleGridX= obstacleX[j] / boxPixelsX;
//                         // if (playerGridX+2 == obstacleGridX)
//                         // teleport=true;
//                     }


// 				}



// 			for (int i = 0; i < powerup_count; i++)
// 			{


// 				if(powerUp_exist[i]){
// 				int powerGridX=power_up_x[i]/boxPixelsX;
// 				int powerGridY=power_up_y[i]/boxPixelsY;

// 				if(playerGridX==powerGridX && playerGridY+1==powerGridY){

// 		    		if(i%4==0)
//             		    decheight=true;
//             		else if(i%4==1)
//             		    incheight=true;
//             		else if(i%4==2)
//             		    decspeed=true;
//             		else if(i%4==3)
// 						incspeed=true;

// 				powerUp_exist[i]=false;
// 				break;
// 				}
// 				}
// 			}

// 			for (int i = 0; i < powerup_count; i++)
// 			{
// 				if(powerUp_exist[i] && powerUpVisible[i].getElapsedTime()>=seconds(7)){
// 					powerUp_exist[i]=false;
// 				}
// 			}





// 	 float speed=1;
//     if (Keyboard::isKeyPressed(Keyboard::Left)) {
//         player_x-=speed;
// 	    		if(player_x<0)
// 	    		player_x=0;



//     }
//     if (Keyboard::isKeyPressed(Keyboard::Right)) {
//         player_x+=speed;
// 	    		if(player_x > resolutionX- (boxPixelsX*2))
// 	    		player_x=resolutionX- (boxPixelsX*2);

//     }


// }







void DrawingHives(RenderWindow& window, Sprite HiveSprite[], float Hive_x[], float Hive_y[], bool BeeHive_exist[], int current_R_bees) {
    for (int i = 0; i < current_R_bees; i++)
        if (BeeHive_exist[i]) {
            HiveSprite[i].setPosition(Hive_x[i], Hive_y[i]);
            window.draw(HiveSprite[i]);
        }

}

void Drawing_Red_Combs(RenderWindow& window, Sprite R_honeycombSprite[], float R_honeycomb_x[], float R_honeycomb_y[], bool R_honeycomb_exist[], int Kill_bees_count) {
    for (int i = 0; i < Kill_bees_count; i++)
    {
        if (R_honeycomb_exist[i])
        {
            R_honeycombSprite[i].setPosition(R_honeycomb_x[i], R_honeycomb_y[i]);
            window.draw(R_honeycombSprite[i]);
        }
    }

}

void Drawing_Yellow_Combs(RenderWindow& window, Sprite Y_honeycombSprite[], float Y_honeycomb_x[], float Y_honeycomb_y[], bool Y_honeycomb_exist[], int current_R_bees) {
    for (int i = 0; i < current_R_bees; i++)
    {
        if (Y_honeycomb_exist[i])
        {
            Y_honeycombSprite[i].setPosition(Y_honeycomb_x[i], Y_honeycomb_y[i]);
            window.draw(Y_honeycombSprite[i]);
        }
    }

}
void Drawing_random_Combs(RenderWindow& window, Sprite rand_combSprite[], float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], int rand_combs) {
    for (int i = 0; i < rand_combs; i++) {
        if (rand_comb_exist[i]) {
            rand_combSprite[i].setPosition(rand_comb_x[i], rand_comb_y[i]);
            window.draw(rand_combSprite[i]);
        }
    }

}


void drawPlayer(RenderWindow& window, float& player_x, float& player_y, Sprite& playerSprite) {
    playerSprite.setPosition(player_x, player_y);
    window.draw(playerSprite);
}
void moveBullet(float& bullet_y, bool& bullet_exists, Clock& bulletClock, Music& bgMusic) {
    if (bulletClock.getElapsedTime().asMilliseconds() < 20)
        return;

    bulletClock.restart();
    bullet_y -= 20;
    if (bullet_y < -32) {
        bullet_exists = false;
        bgMusic.setVolume(50);
    }
}
void drawBullet(sf::RenderWindow& window, float& bullet_x, float& bullet_y, Sprite& bulletSprite) {
    bulletSprite.setPosition(bullet_x + 16, bullet_y);
    window.draw(bulletSprite);
}

void MovePlayer(float& player_x, Clock& movementClock, float obstacleX[], float obstacleY[], int& remainingLives) {
    static bool teleport = false;


    int playerGridX = player_x / boxPixelsX;
    for (int i = 0; i < gameRows; i++)
    {
        int obstacleGridX = obstacleX[i] / boxPixelsX;
        if (playerGridX == obstacleGridX)
            player_x += 1;
        if (playerGridX + 2 == obstacleGridX)
            player_x -= 1;
        if (playerGridX == obstacleGridX)
            for (int j = 0; j < gameRows; j++)
            {
                int obstacleGridX = obstacleX[j] / boxPixelsX;
                if (playerGridX + 2 == obstacleGridX)
                    remainingLives = 0;
            }


    }




    float speed = 0.3;
    if (Keyboard::isKeyPressed(Keyboard::Left)) {
        player_x -= speed;
        if (player_x < 0)
            player_x = 0;



    }
    if (Keyboard::isKeyPressed(Keyboard::Right)) {
        player_x += speed;
        if (player_x > resolutionX - (boxPixelsX * 2))
            player_x = resolutionX - (boxPixelsX * 2);

    }


}

void Firing(bool& bullet_exists, float& bullet_x, float& bullet_y, float player_x, float player_y, bool& spacePressed, Music& fireSound, Music& bgMusic, int& remainingFires, int& firedBullets, int& remainingLives, RectangleShape& magazine, int& magazineBlock) {

    if (Keyboard::isKeyPressed(Keyboard::Space)) {
        if (!spacePressed && !bullet_exists) {
            fireSound.play();
            bgMusic.setVolume(5);
            bullet_exists = true;
            bullet_x = player_x;
            bullet_y = player_y;
            spacePressed = true;

            remainingFires--;
            firedBullets++;

            if (firedBullets == 8) {
                float newHeight = boxPixelsY - 4 * magazineBlock;
                magazine.setSize(Vector2f(boxPixelsX, newHeight));
                firedBullets = 0; // Reset bullet count for the next block
                magazineBlock++;
            }
        }
    }
    else
        spacePressed = false;

    if (remainingFires == 0 && remainingLives > 0) {
        remainingLives--;
        remainingFires = 64;
        firedBullets = 0;
        magazineBlock = 1;

        // Reset magazine size
        magazine.setSize(Vector2f(boxPixelsX, boxPixelsY));
    }



}

void updateGrid(float player_x, float player_y, float bullet_x, float bullet_y, float R_bee_x[], float R_bee_y[], bool R_bee_exist[], int beeCount, float Y_honeycomb_x[], float Y_honeycomb_y[], float K_bee_x[], float K_bee_y[], bool K_bee_exist[], int k_beeCount, float R_honeycomb_x[], float R_honeycomb_y[], bool& bullet_exists, Music& bgMusic, Music& hitSound, bool Y_honeycomb_exist[], bool R_honeycomb_exist[], float Hive_x[], float Hive_y[], bool HiveStatus[], float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], unsigned int& score, const int rand_combs) {

    int bulletGridX = bullet_x / boxPixelsX;
    int bulletGridY = bullet_y / boxPixelsY;

    for (int i = 0; i < beeCount; i++) {
        if (HiveStatus[i]) {
            int HiveGridX = Hive_x[i] / boxPixelsX;
            int HiveGridY = Hive_y[i] / boxPixelsY;


            if (HiveGridX == bulletGridX && HiveGridY == bulletGridY && bulletGridY < 16) {
                bullet_exists = false;
                HiveStatus[i] = false;
                bgMusic.setVolume(50);
                hitSound.play();
                Hive_x[i] = 0;
                Hive_y[i] = 0;

            }
        }
    }


    for (int i = 0; i < beeCount; i++) {
        if (Y_honeycomb_exist[i]) {
            int YcombGridX = Y_honeycomb_x[i] / boxPixelsX;
            int YcombGridY = Y_honeycomb_y[i] / boxPixelsY;


            if (YcombGridX == bulletGridX && YcombGridY == bulletGridY && bulletGridY < 16) {
                bullet_exists = false;
                Y_honeycomb_exist[i] = false;
                bgMusic.setVolume(50);
                hitSound.play();
                Y_honeycomb_x[i] = -64;
                Y_honeycomb_y[i] = -64;

            }
        }
    }

    for (int i = 0; i < k_beeCount; i++) {
        if (R_honeycomb_exist[i]) {

            int RcombGridX = R_honeycomb_x[i] / boxPixelsX;
            int RcombGridY = R_honeycomb_y[i] / boxPixelsY;


            if (RcombGridX == bulletGridX && RcombGridY == bulletGridY && bulletGridY < 16) {
                bullet_exists = false;
                R_honeycomb_exist[i] = false;
                bgMusic.setVolume(50);
                hitSound.play();
                R_honeycomb_x[i] = -64;
                R_honeycomb_y[i] = -64;

            }
        }
    }

    for (int i = 0; i < rand_combs; i++) {
        if (rand_comb_exist[i]) {

            int randcombGridX = rand_comb_x[i] / boxPixelsX;
            int randcombGridY = rand_comb_y[i] / boxPixelsY;


            if (randcombGridX == bulletGridX && randcombGridY == bulletGridY && bulletGridY < 16) {
                bullet_exists = false;
                rand_comb_exist[i] = false;
                bgMusic.setVolume(50);
                hitSound.play();
                rand_comb_x[i] = -64;
                rand_comb_y[i] = -64;

            }
        }

    }


    for (int i = 0; i < beeCount; i++) {
        if (R_bee_exist[i]) {
            int beeGridX = R_bee_x[i] / boxPixelsX;
            int beeGridY = R_bee_y[i] / boxPixelsY;


            if (beeGridX == bulletGridX && beeGridY == bulletGridY && bulletGridY < 16) {
                score += 100;
                cout << score << endl;
                bullet_exists = false;
                R_bee_exist[i] = false;
                bgMusic.setVolume(50);
                hitSound.play();
                Y_honeycomb_exist[i] = true;
                Y_honeycomb_x[i] = R_bee_x[i];
                Y_honeycomb_y[i] = R_bee_y[i];

            }
        }


    }
    for (int i = 0; i < k_beeCount; i++) {
        if (K_bee_exist[i]) {


            int K_beeGridX = K_bee_x[i] / boxPixelsX;
            int K_beeGridY = K_bee_y[i] / boxPixelsY;

            if (K_beeGridX == bulletGridX && K_beeGridY == bulletGridY && bulletGridY < 16) {
                score += 1000;
                cout << score << endl;
                bullet_exists = false;
                K_bee_exist[i] = false;
                bgMusic.setVolume(50);
                hitSound.play();
                R_honeycomb_exist[i] = true;
                R_honeycomb_x[i] = K_bee_x[i];
                R_honeycomb_y[i] = K_bee_y[i];
            }
        }
    }


}





void RegularBeesManager(RenderWindow& window, Clock& regularBeeNext, int& current_R_bees, const int max_R_bees, bool R_bee_exist[], Sprite regularBeeSprite[], float R_bee_x[], float R_bee_y[], int beeDirection[], float Y_honeycomb_x[], float Y_honeycomb_y[], bool Y_honeycomb_exist[], Clock beeStay[], float Hive_x[], float Hive_y[], bool BeeHive_exist[], float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], const int rand_combs, Clock& R_bees_animation, float R_honeycomb_x[], float R_honeycomb_y[], bool R_honeycomb_exist, int current_K_bees) {

    static bool paused[20] = { false };


    if (regularBeeNext.getElapsedTime() >= seconds(1) && current_R_bees < max_R_bees) {
        R_bee_exist[current_R_bees] = true;
        current_R_bees++;
        regularBeeNext.restart();
    }
    float moveSpeed = 0.25;
    for (int i = 0; i < current_R_bees; i++) {


        if (R_bees_animation.getElapsedTime() <= seconds(0.05))
        {
            regularBeeSprite[i].setTextureRect(IntRect(0, 0, 32, 32)); /* code */
            regularBeeSprite[i].setOrigin(16, 0);
        }
        else if (R_bees_animation.getElapsedTime() <= seconds(0.1))
        {
            regularBeeSprite[i].setTextureRect(IntRect(32, 0, 32, 32));
            regularBeeSprite[i].setOrigin(16, 0);
        }
        else if (R_bees_animation.getElapsedTime() <= seconds(0.15))
        {
            regularBeeSprite[i].setTextureRect(IntRect(64, 0, 32, 32));
            regularBeeSprite[i].setOrigin(16, 0);
        }
        else if (R_bees_animation.getElapsedTime() <= seconds(0.2))
        {
            regularBeeSprite[i].setTextureRect(IntRect(96, 0, 32, 32));
            regularBeeSprite[i].setOrigin(16, 0);
        }
        else
        {
            R_bees_animation.restart();
        }


        if (R_bee_exist[i]) {

            if (!paused[i]) {

                if (rand() % 1000 == 0) {
                    paused[i] = true;
                    beeStay[i].restart();
                }
            }
            else {

                if (beeStay[i].getElapsedTime().asSeconds() >= 0.4) {
                    paused[i] = false;
                    beeStay[i].restart();
                }
                else {
                    continue;
                }
            }


            int beeGridX = R_bee_x[i] / boxPixelsX;
            int beeGridY = R_bee_y[i] / boxPixelsY;

            for (int j = 0; j < max_R_bees; j++) {
                if (Y_honeycomb_exist[j] || rand_comb_exist[j]) {
                    int combGridX = Y_honeycomb_x[j] / boxPixelsX;
                    int combGridY = Y_honeycomb_y[j] / boxPixelsY;

                    int RcombGridX = R_honeycomb_x[j] / boxPixelsX;
                    int RcombGridY = R_honeycomb_y[j] / boxPixelsY;

                    int randcombGridX = rand_comb_x[j] / boxPixelsX;
                    int randcombGridY = rand_comb_y[j] / boxPixelsY;

                    if (beeGridX + 1 == combGridX && beeGridY == combGridY && beeDirection[i] == 1 || beeGridX + 1 == randcombGridX && beeGridY == randcombGridY && beeDirection[i] == 1 || beeGridX + 1 == RcombGridX && beeGridY == RcombGridY && beeDirection[i] == 1) {
                        beeDirection[i] = -1;
                        regularBeeSprite[i].setScale(1.8f, 1.8f);

                        if (BeeHiveCheck(R_bee_x[i], R_bee_y[i], Hive_x, Hive_y, current_R_bees, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, BeeHive_exist)) {
                            R_bee_exist[i] = false;
                            Hive_x[i] = R_bee_x[i];
                            Hive_y[i] = R_bee_y[i] - boxPixelsY;

                            BeeHive_exist[i] = true;
                        }
                        else
                            R_bee_y[i] += boxPixelsY;
                        beeStay[i].restart();

                        break;
                    }
                    else if (beeGridX - 1 == combGridX && beeGridY == combGridY && beeDirection[i] == -1 || beeGridX - 1 == randcombGridX && beeGridY == randcombGridY && beeDirection[i] == -1 || beeGridX - 1 == RcombGridX && beeGridY == RcombGridY && beeDirection[i] == -1) {
                        beeDirection[i] = 1;


                        regularBeeSprite[i].setScale(-1.8f, 1.8f);

                        if (BeeHiveCheck(R_bee_x[i], R_bee_y[i], Hive_x, Hive_y, current_R_bees, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, BeeHive_exist)) {
                            R_bee_exist[i] = false;
                            Hive_x[i] = R_bee_x[i];
                            Hive_y[i] = R_bee_y[i] - boxPixelsY;

                            BeeHive_exist[i] = true;
                        }
                        else
                            R_bee_y[i] += boxPixelsY;
                        beeStay[i].restart();

                        break;
                    }
                }
            }

            if (!paused[i]) {


                R_bee_x[i] += moveSpeed * beeDirection[i];


                if (R_bee_x[i] >= resolutionX && beeDirection[i] == 1) {
                    beeDirection[i] = -1;

                    if (BeeHiveCheck(R_bee_x[i], R_bee_y[i], Hive_x, Hive_y, current_R_bees, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, BeeHive_exist)) {
                        R_bee_exist[i] = false;
                        Hive_x[i] = R_bee_x[i];
                        Hive_y[i] = R_bee_y[i] - boxPixelsY;

                        BeeHive_exist[i] = true;
                    }
                    else
                        R_bee_y[i] += boxPixelsY;

                    regularBeeSprite[i].setScale(1.8f, 1.8f);
                }
                else if (R_bee_x[i] <= 0 && beeDirection[i] == -1) {
                    beeDirection[i] = 1;

                    if (BeeHiveCheck(R_bee_x[i], R_bee_y[i], Hive_x, Hive_y, current_R_bees, Y_honeycomb_x, Y_honeycomb_y, Y_honeycomb_exist, BeeHive_exist)) {
                        R_bee_exist[i] = false;
                        Hive_x[i] = R_bee_x[i];
                        Hive_y[i] = R_bee_y[i] - boxPixelsY;

                        BeeHive_exist[i] = true;
                    }
                    else
                        R_bee_y[i] += boxPixelsY;

                    regularBeeSprite[i].setScale(-1.8f, 1.8f);
                }


                regularBeeSprite[i].setPosition(R_bee_x[i], R_bee_y[i]);
            }
        }
    }



    for (int i = 0; i < current_R_bees; i++) {
        if (R_bee_exist[i]) {
            window.draw(regularBeeSprite[i]);
        }
    }
}










void KillerBeesManager(RenderWindow& window, Clock& KillerBeeNext, int& current_K_bees, const int max_K_bees, bool K_bee_exist[], Sprite KillerBeeSprite[], float K_bee_x[], float K_bee_y[], int K_beeDirection[], float R_honeycomb_x[], float R_honeycomb_y[], bool R_honeycomb_exist[]) {




    if (KillerBeeNext.getElapsedTime() >= seconds(5) && current_K_bees < max_K_bees) {
        K_bee_exist[current_K_bees] = true;
        current_K_bees++;
        KillerBeeNext.restart();
    }
    float moveSpeed = 2;
    for (int i = 0; i < current_K_bees; i++) {





        if (K_bee_exist[i]) {



            int KbeeGridX = K_bee_x[i] / boxPixelsX;
            int KbeeGridY = K_bee_y[i] / boxPixelsY;






            K_bee_x[i] += moveSpeed * K_beeDirection[i];


            if (K_bee_x[i] >= resolutionX - boxPixelsX && K_beeDirection[i] == 1) {
                K_beeDirection[i] = -1;
                K_bee_y[i] += boxPixelsY;

                KillerBeeSprite[i].setScale(1.2, 1.2);
            }
            else if (K_bee_x[i] <= 0 && K_beeDirection[i] == -1) {
                K_beeDirection[i] = 1;
                K_bee_y[i] += boxPixelsY;

                KillerBeeSprite[i].setScale(-1.2, 1.2);
            }


            KillerBeeSprite[i].setPosition(K_bee_x[i], K_bee_y[i]);

        }
    }



    for (int i = 0; i < current_K_bees; i++) {
        if (K_bee_exist[i]) {
            window.draw(KillerBeeSprite[i]);
        }
    }
}





int BeeHiveCheck(float R_bee_x, float R_bee_y, float Hive_x[], float Hive_y[], int current_R_bees,
    float Y_honeycomb_x[], float Y_honeycomb_y[], bool Y_honeycomb_exist[], bool BeeHive_exist[]) {
    int beeGridY = R_bee_y / boxPixelsY;
    int beeGridX = R_bee_x / boxPixelsX;
    cout << R_bee_x << endl;
    for (int i = 0; i < current_R_bees; i++) {
        if (Y_honeycomb_exist[i]) {
            int combGridX = Y_honeycomb_x[i] / boxPixelsX;
            int combGridY = Y_honeycomb_y[i] / boxPixelsY;
            cout << "                  " << Y_honeycomb_x[i] << endl;


            bool leftcheck = (R_bee_x - 64 <= Y_honeycomb_x[i] && combGridY == beeGridY && cout << "left");
            bool rightcheck = (R_bee_x + 64 >= Y_honeycomb_x[i] && combGridY == beeGridY && cout << "right");
            bool bottomcheck = (combGridX == beeGridX && R_bee_y + 64 >= Y_honeycomb_y[i] && cout << "bottom");


            if (leftcheck && rightcheck && bottomcheck) {
                cout << "Beehive formed at (" << beeGridX << ", " << beeGridY << ")" << endl;
                return 1;
            }
            else if (R_bee_x <= boxPixelsX * 3 && rightcheck && bottomcheck) {
                cout << "Beehive formed at (" << beeGridX << ", " << beeGridY << ")" << endl;
                return 1;
            }
            else if (leftcheck && R_bee_x >= resolutionX - boxPixelsX * 3 && bottomcheck) {
                cout << "Beehive formed at (" << beeGridX << ", " << beeGridY << ")" << endl;
                return 1;
            }
        }
    }

    // If no valid beehive is formed
    return 0;
}







void obstaclesManager(RenderWindow& window, Sprite obstacleSprite[], float beeX[], float beeY[], int current_R_bees, bool R_bees_exist[], float obstacleX[], float obstacleY[], int& obstacleCount, float& player_x, float K_bee_x[], float K_bee_y[], bool K_bees_exist[], int& space, int& Left, int& Right, int kill_beeCount) {

    float middle = resolutionX / 2;
    int playerGridX = player_x / boxPixelsX;
    for (int i = 0; i < current_R_bees; i++) {
        int beeGridY = beeY[i] / boxPixelsY;
        int beeGridX = beeX[i] / boxPixelsX;



        if ((beeGridY == 16 || beeGridY == 17) && R_bees_exist[i] == true) {
            obstacleY[obstacleCount] = beeY[i] + boxPixelsY;
            if (beeGridX == 0) {
                if (Left < 1) {
                    obstacleX[obstacleCount] = Left * boxPixelsX;
                    obstacleY[obstacleCount] = resolutionY - boxPixelsY * 3;
                    Left++;
                    obstacleCount++;
                }
                if (Left >= 1) {
                    obstacleX[obstacleCount] = Left * boxPixelsX;
                    obstacleY[obstacleCount] = resolutionY - boxPixelsY * 3;
                    Left++;
                    obstacleCount++;

                }

            }
            else if (beeGridX == (resolutionX - boxPixelsX) / boxPixelsX) {
                if (Right < 2) {
                    obstacleX[obstacleCount] = resolutionX - Right * boxPixelsX;
                    obstacleY[obstacleCount] = resolutionY - boxPixelsY * 3;
                    Right++;
                    obstacleCount++;
                }
                if (Right >= 2) {
                    obstacleX[obstacleCount] = resolutionX - Right * boxPixelsX;
                    obstacleY[obstacleCount] = resolutionY - boxPixelsY * 3;
                    Right++;
                    obstacleCount++;
                }
            }
            else {
                if (space & 1) {
                    obstacleX[obstacleCount] = middle - space / 2 * boxPixelsX;
                    space++;
                    obstacleCount++;
                }
                else {
                    obstacleX[obstacleCount] = middle + space / 2 * boxPixelsX;
                    space++;
                    obstacleCount++;
                }

            }
            R_bees_exist[i] = false;
        }
    }




    for (int i = 0; i < kill_beeCount; i++)
    {

        int K_beeGridY = K_bee_y[i] / boxPixelsY;
        int K_beeGridX = K_bee_x[i] / boxPixelsX;
        if ((K_beeGridY == 16 || K_beeGridY == 17) && K_bees_exist[i] == true) {
            if (K_beeGridX == 0) {
                if (Left < 1) {
                    obstacleX[obstacleCount] = Left * boxPixelsX;
                    obstacleY[obstacleCount] = resolutionY - boxPixelsY * 3;
                    Left++;
                    obstacleCount++;
                }
                if (Left >= 1) {
                    obstacleX[obstacleCount] = Left * boxPixelsX;
                    obstacleY[obstacleCount] = resolutionY - boxPixelsY * 3;
                    Left++;
                    obstacleCount++;

                }


            }
            else if (K_beeGridX == (resolutionX - boxPixelsX) / boxPixelsX) {
                if (Right < 2) {
                    obstacleX[obstacleCount] = resolutionX - Right * boxPixelsX;
                    obstacleY[obstacleCount] = resolutionY - boxPixelsY * 3;
                    Right++;
                    obstacleCount++;
                }
                if (Right >= 2) {
                    obstacleX[obstacleCount] = resolutionX - Right * boxPixelsX;
                    obstacleY[obstacleCount] = resolutionY - boxPixelsY * 3;
                    Right++;
                    obstacleCount++;
                }
            }
            else {
                if (space & 1) {
                    obstacleX[obstacleCount] = middle - space / 2 * boxPixelsX;
                    space++;
                    obstacleCount++;
                }
                else {
                    obstacleX[obstacleCount] = middle + space / 2 * boxPixelsX;
                    space++;
                    obstacleCount++;
                }
            }
            // obstacleCount++;
            K_bees_exist[i] = false;
        }
    }


    for (int i = 0; i < obstacleCount; i++) {


        obstacleSprite[i].setPosition(obstacleX[i], obstacleY[i]);
        window.draw(obstacleSprite[i]);

    }

}







//For Boss Level
void humminbirdManager(RenderWindow& window, Clock& Bird, Clock& BirdMove, Sprite& BirdSprite, float& bird_x, float& bird_y, float honeycomb_x[], float honeycomb_y[], bool honeycomb_exist[], int current_R_bees, bool SickStatus, float K_honeycomb_x[], float K_honeycomb_y[], bool K_honeycomb_exist[], int Kill_beeCount, unsigned int& score, float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], const int rand_combs, float power_up_x[], float power_up_y[], bool powerUp_exist[], int& powerup_count, Clock powerUpVisible[]) {
    const float bird_speed = 0.8f;


    static bool collision = false;
    static bool K_collision = false;
    static bool r_collision = false;

    static bool isPaused = false;
    static bool combcollision = false;

    static int birdDirect_x = 1;
    static int birdDirect_y = 1;

    static int h = 19;





    // Animate the bird sprite
    if (Bird.getElapsedTime() <= seconds(0.2)) {
        BirdSprite.setTextureRect(IntRect(32, 0, 32, 32));
    }
    else if (Bird.getElapsedTime() <= seconds(0.5)) {
        BirdSprite.setTextureRect(IntRect(0, 0, 32, 32));
    }
    else {
        Bird.restart();
    }

    // Get the bird's grid position
    int birdGridX = bird_x / 64;
    int birdGridY = bird_y / 64;

    // Handle screen boundary collisions (if bird is not sick)
    if (!SickStatus) {
        if (bird_x >= resolutionX - boxPixelsX - 16) {
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
            collision = true;
            bird_x -= 1;
        }
        else if (bird_x <= boxPixelsX) {
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
            collision = true;
            bird_x += 1;
        }
        else if (bird_y <= boxPixelsY) {
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
            collision = true;
            bird_y += 1;
        }
        else if (bird_y >= 470) {
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
            collision = true;
            bird_y -= 1;
        }
    }

    // Check collision with regular honeycombs
    for (int i = 0; i < current_R_bees; i++) {
        if (honeycomb_exist[i]) {

            int combGridX = honeycomb_x[i] / 64;
            int combGridY = honeycomb_y[i] / 64;

            if (birdGridX == combGridX && birdGridY == combGridY && !collision) {
                bird_x = honeycomb_x[i];
                bird_y = honeycomb_y[i];
                BirdPowerUp(honeycomb_x[i], honeycomb_y[i], power_up_x, power_up_y, powerUp_exist, powerup_count, powerUpVisible);
                collision = true;
                if (honeycomb_y[i] >= boxPixelsY && honeycomb_y[i] < boxPixelsY * 3)
                    score += 1000;
                else if (honeycomb_y[i] >= boxPixelsY * 3 && honeycomb_y[i] < boxPixelsY * 6)
                    score += 800;
                else
                    score += 500;
                h = i;
                break;
            }
        }
    }
    // Check collision with Khoneycombs
    for (int i = 0; i < Kill_beeCount; i++) {
        if (rand_comb_exist[i]) {

            int randcombGridX = rand_comb_x[i] / 64;
            int randcombGridY = rand_comb_y[i] / 64;

            if (birdGridX == randcombGridX && birdGridY == randcombGridY && !collision) {
                bird_x = rand_comb_x[i];
                bird_y = rand_comb_y[i];
                BirdPowerUp(rand_comb_x[i], rand_comb_y[i], power_up_x, power_up_y, powerUp_exist, powerup_count, powerUpVisible);
                if (rand_comb_y[i] >= boxPixelsY && rand_comb_y[i] < boxPixelsY * 3)
                    score += 1000;
                else if (rand_comb_y[i] >= boxPixelsY * 3 && rand_comb_y[i] < boxPixelsY * 6)
                    score += 800;
                else
                    score += 500;
                r_collision = true;
                collision = true;
                h = i;
                break;
            }
        }
    }
    for (int i = 0; i < Kill_beeCount; i++) {
        if (!K_honeycomb_exist[i]) continue;

        int K_combGridX = K_honeycomb_x[i] / 64;
        int K_combGridY = K_honeycomb_y[i] / 64;

        if (birdGridX == K_combGridX && birdGridY == K_combGridY && !collision) {
            bird_x = K_honeycomb_x[i];
            bird_y = K_honeycomb_y[i];
            BirdPowerUp(K_honeycomb_x[i], K_honeycomb_y[i], power_up_x, power_up_y, powerUp_exist, powerup_count, powerUpVisible);
            if (K_honeycomb_y[i] >= boxPixelsY && K_honeycomb_y[i] < boxPixelsY * 3)
                score += 2000;
            else if (K_honeycomb_y[i] >= boxPixelsY * 3 && K_honeycomb_y[i] < boxPixelsY * 6)
                score += 1800;
            else
                score += 1500;

            collision = true;
            K_collision = true;
            h = i;
            break;
        }
    }

    // Handle collision pause
    if (collision) {
        if (!isPaused) {
            BirdMove.restart(); // Start the pause timer
            isPaused = true;
        }


        if (BirdMove.getElapsedTime() >= seconds(1.2)) {
            collision = false;
            isPaused = false;

            if (K_collision) {

                K_honeycomb_exist[h] = false;

                K_honeycomb_x[h] = -560;
                K_honeycomb_y[h] = -534;
                K_collision = false;
                collision = false;
            }
            else if (r_collision) {

                rand_comb_exist[h] = false;
                rand_comb_x[h] = -560;
                rand_comb_y[h] = -534;
                r_collision = false;
                collision = false;
            }
            else
            {
                honeycomb_exist[h] = false;

                honeycomb_x[h] = -560;
                honeycomb_y[h] = -534;
                collision = false;
            }



            BirdMove.restart();
        }
    }


    if (!collision && !isPaused) {
        if (BirdMove.getElapsedTime() <= seconds(1)) {
            bird_x += bird_speed * birdDirect_x;
            bird_y += 0.3f * birdDirect_y;
        }
        else {
            collision = true;
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
        }
    }


    if (birdDirect_x == -1) {
        BirdSprite.setScale(-2.6, 2.5);
        BirdSprite.setOrigin(32 * 3 / 4.f, 32 / 2.f);
    }
    else if (birdDirect_x == 1) {
        BirdSprite.setOrigin(32 / 4.f, 32 / 2.f);
        BirdSprite.setScale(2.6, 2.5);
    }


    BirdSprite.setPosition(bird_x, bird_y);
    window.draw(BirdSprite);
}


void BirdPowerUp(int x, int y, float power_up_x[], float power_up_y[], bool powerUp_exist[], int& powerup_count, Clock powerUpVisible[]) {
    power_up_x[powerup_count] = x;
    power_up_y[powerup_count] = y;
    powerUp_exist[powerup_count] = true;
    powerUpVisible[powerup_count].restart();
    powerup_count++;
}





void humminbirdManager(RenderWindow& window, Clock& Bird, Clock& BirdMove, Sprite& BirdSprite, float& bird_x, float& bird_y, float honeycomb_x[], float honeycomb_y[], bool honeycomb_exist[], int current_R_bees, bool SickStatus, float K_honeycomb_x[], float K_honeycomb_y[], bool K_honeycomb_exist[], int Kill_beeCount, unsigned int& score, float rand_comb_x[], float rand_comb_y[], bool rand_comb_exist[], const int rand_combs) {
    const float bird_speed = 0.8f;


    static bool collision = false;
    static bool K_collision = false;
    static bool r_collision = false;

    static bool isPaused = false;
    static bool combcollision = false;

    static int birdDirect_x = 1;
    static int birdDirect_y = 1;

    static int h = 19;





    // Animate the bird sprite
    if (Bird.getElapsedTime() <= seconds(0.2)) {
        BirdSprite.setTextureRect(IntRect(32, 0, 32, 32));
    }
    else if (Bird.getElapsedTime() <= seconds(0.5)) {
        BirdSprite.setTextureRect(IntRect(0, 0, 32, 32));
    }
    else {
        Bird.restart();
    }

    // Get the bird's grid position
    int birdGridX = bird_x / 64;
    int birdGridY = bird_y / 64;

    // Handle screen boundary collisions (if bird is not sick)
    if (!SickStatus) {
        if (bird_x >= resolutionX - boxPixelsX - 16) {
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
            collision = true;
            bird_x -= 1;
        }
        else if (bird_x <= boxPixelsX) {
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
            collision = true;
            bird_x += 1;
        }
        else if (bird_y <= boxPixelsY) {
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
            collision = true;
            bird_y += 1;
        }
        else if (bird_y >= 470) {
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
            collision = true;
            bird_y -= 1;
        }
    }

    // Check collision with regular honeycombs
    for (int i = 0; i < current_R_bees; i++) {
        if (honeycomb_exist[i]) {

            int combGridX = honeycomb_x[i] / 64;
            int combGridY = honeycomb_y[i] / 64;

            if (birdGridX == combGridX && birdGridY == combGridY && !collision) {
                bird_x = honeycomb_x[i];
                bird_y = honeycomb_y[i];
                collision = true;
                if (honeycomb_y[i] >= boxPixelsY && honeycomb_y[i] < boxPixelsY * 3)
                    score += 1000;
                else if (honeycomb_y[i] >= boxPixelsY * 3 && honeycomb_y[i] < boxPixelsY * 6)
                    score += 800;
                else
                    score += 500;
                h = i;
                break;
            }
        }
    }
    // Check collision with Khoneycombs
    for (int i = 0; i < Kill_beeCount; i++) {
        if (rand_comb_exist[i]) {

            int randcombGridX = rand_comb_x[i] / 64;
            int randcombGridY = rand_comb_y[i] / 64;

            if (birdGridX == randcombGridX && birdGridY == randcombGridY && !collision) {
                bird_x = rand_comb_x[i];
                bird_y = rand_comb_y[i];
                if (rand_comb_y[i] >= boxPixelsY && rand_comb_y[i] < boxPixelsY * 3)
                    score += 1000;
                else if (rand_comb_y[i] >= boxPixelsY * 3 && rand_comb_y[i] < boxPixelsY * 6)
                    score += 800;
                else
                    score += 500;
                r_collision = true;
                collision = true;
                h = i;
                break;
            }
        }
    }
    for (int i = 0; i < Kill_beeCount; i++) {
        if (!K_honeycomb_exist[i]) continue;

        int K_combGridX = K_honeycomb_x[i] / 64;
        int K_combGridY = K_honeycomb_y[i] / 64;

        if (birdGridX == K_combGridX && birdGridY == K_combGridY && !collision) {
            bird_x = K_honeycomb_x[i];
            bird_y = K_honeycomb_y[i];
            if (K_honeycomb_y[i] >= boxPixelsY && K_honeycomb_y[i] < boxPixelsY * 3)
                score += 2000;
            else if (K_honeycomb_y[i] >= boxPixelsY * 3 && K_honeycomb_y[i] < boxPixelsY * 6)
                score += 1800;
            else
                score += 1500;

            collision = true;
            K_collision = true;
            h = i;
            break;
        }
    }

    // Handle collision pause
    if (collision) {
        if (!isPaused) {
            BirdMove.restart(); // Start the pause timer
            isPaused = true;
        }


        if (BirdMove.getElapsedTime() >= seconds(1.2)) {
            collision = false;
            isPaused = false;

            if (K_collision) {

                K_honeycomb_exist[h] = false;

                K_honeycomb_x[h] = -560;
                K_honeycomb_y[h] = -534;
                K_collision = false;
                collision = false;
            }
            else if (r_collision) {

                rand_comb_exist[h] = false;
                rand_comb_x[h] = -560;
                rand_comb_y[h] = -534;
                r_collision = false;
                collision = false;
            }
            else
            {
                honeycomb_exist[h] = false;

                honeycomb_x[h] = -560;
                honeycomb_y[h] = -534;
                collision = false;
            }



            BirdMove.restart();
        }
    }


    if (!collision && !isPaused) {
        if (BirdMove.getElapsedTime() <= seconds(1)) {
            bird_x += bird_speed * birdDirect_x;
            bird_y += 0.3f * birdDirect_y;
        }
        else {
            collision = true;
            birdDirect_x = rand() % 3 - 1;
            birdDirect_y = rand() % 3 - 1;
        }
    }


    if (birdDirect_x == -1) {
        BirdSprite.setScale(-2.6, 2.5);
        BirdSprite.setOrigin(32 * 3 / 4.f, 32 / 2.f);
    }
    else if (birdDirect_x == 1) {
        BirdSprite.setOrigin(32 / 4.f, 32 / 2.f);
        BirdSprite.setScale(2.6, 2.5);
    }


    BirdSprite.setPosition(bird_x, bird_y);
    window.draw(BirdSprite);
}







void HummingBird_Health(float& bullet_x, float& bullet_y, float& bird_x, float& bird_y, bool& SickStatus, bool& bullet_exist, Sprite& BirdSprite, Clock& SickTime, Music& BirdHitSound, Music& bgMusic) {
    static int Bird_hit = 0;

    int birdGridX = bird_x / boxPixelsX;
    int birdGridY = bird_y / boxPixelsY;

    int bulletGridX = bullet_x / boxPixelsX;
    int bulletGridY = bullet_y / boxPixelsY;


    if (bullet_exist && bulletGridX == birdGridX && bulletGridY == birdGridY) {
        cout << "Hit" << endl;
        BirdHitSound.play();
        bgMusic.setVolume(50);
        Bird_hit++;
        bullet_exist = false;
    }


    if (Bird_hit >= 3 && !SickStatus) {
        Bird_hit = 0;
        SickStatus = true;
        SickTime.restart();
    }

    if (SickStatus) {
        if (SickTime.getElapsedTime() < seconds(5)) {
            BirdSprite.setColor(Color::Green); // Sick (green)
            bird_x += 1;
        }
        else {
            SickStatus = false;               // Recover after 5 seconds
            BirdSprite.setColor(Color::Red);
        }
    }
    else {

        BirdSprite.setColor(Color::Red);
        BirdSprite.setPosition(resolutionX, bird_y);
    }
}



