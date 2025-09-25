// PROJECT MADE BY MARCOS BERBEL PASCUAL (2025).

#include <iostream> // standard library
#include <cstdlib> // random numbers
#include <vector> // vectors library
#include <cctype> // isalpha()

using namespace std;

const int MAPSIZE = 7; // symmetric map
const vector<vector<int>> combinations = {{1, 2, 3}, {1, 5, 9}, {1, 4, 7},
                                {3, 6, 9}, {3, 5, 7}, {7, 8, 9},
                                {2, 5, 8}, {4, 5, 6}};

void printBoard(char board[MAPSIZE][MAPSIZE]){ // 3x3 board

    for(int i = 0; i < MAPSIZE; i++){
        for(int j = 0; j < MAPSIZE; j++){
            cout << board[i][j];
        }
        cout << endl;
    }
}

void turnSelector(bool &turnX, bool &turnO){
    
    if(rand() - RAND_MAX / 2 < 0){ // produces random positive and negative numbers
        turnO = true;
    }
    else{
        turnX = true;
    }
}

void sortVectorPositions(vector<int> &positions){ // sort the positions selected in ascending order

    int aux = 0;

    for(unsigned int i = 0; i < positions.size(); i++){
        for(unsigned int j = i; j < positions.size(); j++){
            if(positions[i] > positions[j]){
                aux = positions[i];
                positions[i] = positions[j];
                positions[j] = aux;
            }
        }
    }
}

void checkPosition(char board[MAPSIZE][MAPSIZE], int position, bool &correctPosition){

    if(position == 1){
        if(isalpha(board[1][1]) != 0){
            correctPosition = false;
        }
    }
    else if(position == 2){
        if(isalpha(board[1][3]) != 0){
            correctPosition = false;
        }
    }
    else if(position == 3){
        if(isalpha(board[1][5]) != 0){
            correctPosition = false;
        }
    }
    else if(position == 4){
        if(isalpha(board[3][1]) != 0){
            correctPosition = false;
        }
    }
    else if(position == 5){
        if(isalpha(board[3][3]) != 0){
            correctPosition = false;
        }
    }
    else if(position == 6){
        if(isalpha(board[3][5]) != 0){
            correctPosition = false;
        }
    }
    else if(position == 7){
        if(isalpha(board[5][1]) != 0){
            correctPosition = false;
        }
    }
    else if(position == 8){
        if(isalpha(board[5][3]) != 0){
            correctPosition = false;
        }
    }
    else if(position == 9){
        if(isalpha(board[5][5]) != 0){
            correctPosition = false;
        }
    }
    
}

void transformPosition(int position, int &boardPosition1, int &boardPosition2){
    if(position == 1){
        boardPosition1 = 1;
        boardPosition2 = 1;
    }
    else if(position == 2){
        boardPosition1 = 1;
        boardPosition2 = 3;
    }
    else if(position == 3){
        boardPosition1 = 1;
        boardPosition2 = 5;
    }
    else if(position == 4){
        boardPosition1 = 3;
        boardPosition2 = 1;
    }
    else if(position == 5){
        boardPosition1 = 3;
        boardPosition2 = 3;
    }
    else if(position == 6){
        boardPosition1 = 3;
        boardPosition2 = 5;
    }
    else if(position == 7){
        boardPosition1 = 5;
        boardPosition2 = 1;
    }
    else if(position == 8){
        boardPosition1 = 5;
        boardPosition2 = 3;
    }
    else if(position == 9){
        boardPosition1 = 5;
        boardPosition2 = 5;
    }
}

void updateBoard(char board[MAPSIZE][MAPSIZE], int position, bool turnX, bool turnO, bool &correctPosition, bool infiniteGame, int deleteVectorPosition){ // spaces on board are numbered 1-9. User does not have to enter row and column position

    int boardPosition1 = 0;
    int boardPosition2 = 0;

    checkPosition(board, position, correctPosition);

    if(infiniteGame && correctPosition){
        transformPosition(deleteVectorPosition, boardPosition1, boardPosition2);
        board[boardPosition1][boardPosition2] = ' ';
    }

    if(correctPosition){
        transformPosition(position, boardPosition1, boardPosition2);
        if(position == 1){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }     
        }
        else if(position == 2){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }
        }
        else if(position == 3){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }
        }
        else if(position == 4){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }
        }
        else if(position == 5){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }
        }
        else if(position == 6){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }
        } 
        else if(position == 7){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }
        }
        else if(position == 8){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }
        }
        else if(position == 9){
            if(turnX){
                board[boardPosition1][boardPosition2] = 'X';
            }
            else if(turnO){
                board[boardPosition1][boardPosition2] = 'O';
            }
        }
    }
}

void resetBoard(char board[MAPSIZE][MAPSIZE]){
    for(int i = 0; i < MAPSIZE; i++){
        for(int j = 0; j < MAPSIZE; j++){
            if(board[i][j] != '#' && board[i][j] != '|' && board[i][j] != '-' && board[i][j] != ' '){
                board[i][j] = ' ';
            }
        }
        
    }
}

bool checkLines(vector<int> positions){
    bool line = false;

    sortVectorPositions(positions);

    for(unsigned int i = 0; i < combinations.size(); i++){
        if(positions == combinations[i]){
            line = true;
        }
    }

    return line;
}

void editPositionVectors(vector<int>& positions, int position){

    sortVectorPositions(positions);

    positions[0] = position;

    sortVectorPositions(positions);

}

void playGame2players(char board[MAPSIZE][MAPSIZE], vector<vector<int>> combinations){

    vector<int> positionsX;
    vector<int> positionsO;

    bool turnX = false;
    bool turnO = false;
    bool correctPosition = true;
    bool correctOption = false;
    bool lineMade = false;
    bool continueGame = true;

    bool infiniteGame = false;
    int deleteVectorPosition = 0;

    int optionSelected = 0;
    char continueOption;

    printBoard(board);
    turnSelector(turnX, turnO);

    while(!lineMade && continueGame){
        if(turnX){
            do{
                correctPosition = true;
                do{
                    cout << "X turn (0 to leave): ";
                    cin >> optionSelected;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Please enter a number between 1 and 9, or 0 to leave." << endl;
                        correctOption = false;
                    }
                    else if(optionSelected > 0 && optionSelected < 10){
                        correctOption = true;
                    }
                    else if(optionSelected == 0){
                        return;
                    }
                    else{
                        correctOption = false;
                        cout << "Position not valid. Please introduce another valid number" << endl;
                        cin.clear(); // if the user introduces a character the buffer is cleaned to avoid errors
                        cin.ignore();
                    }
                }while(!correctOption);
                
                if(infiniteGame){
                    deleteVectorPosition = positionsX[0];
                }

                updateBoard(board, optionSelected, turnX, turnO, correctPosition, infiniteGame, deleteVectorPosition);
                printBoard(board);

                if(!correctPosition){
                    cout << "This position is already occupied. Please choose another one" << endl;
                }
                else{
                    positionsX.push_back(optionSelected);
                    if(infiniteGame){
                        positionsX.erase(positionsX.begin());
                    }
                    turnX = false;
                    turnO = true;
                }
                if(positionsX.size() == 3){
                    lineMade = checkLines(positionsX);
                    if(lineMade){
                        cout << "X is the Winner!!" << endl;
                        resetBoard(board);
                        positionsX.clear();
                        positionsO.clear();
                    }
                }
            } while(!correctPosition);

            if(!lineMade && positionsX.size()==3 && positionsO.size()==3 && !infiniteGame){
                cout << "The game has ended in a draw" << endl;
                cout << "Do you want to restart (r), leave (l) or continue (c) the game: ";
                cin >> continueOption;

                if(tolower(continueOption)=='r'){
                    continueGame = true;
                    resetBoard(board);
                    printBoard(board);
                    positionsX.clear();
                    positionsO.clear();
                }
                else if(tolower(continueOption)=='l'){
                    continueGame = false;
                    resetBoard(board);
                    positionsX.clear();
                    positionsO.clear();
                }
                else if(tolower(continueOption)=='c'){
                    infiniteGame = true;
                    turnX = false;
                    turnO = true;
                }
            }
        }
        else if(turnO){
            do{
                correctPosition = true;
                do{
                    cout << "O turn (0 to leave): ";
                    cin >> optionSelected;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Please enter a number between 1 and 9, or 0 to leave." << endl;
                        correctOption = false;
                    }
                    else if(optionSelected > 0 && optionSelected < 10){
                        correctOption = true;
                    }
                    else if(optionSelected == 0){
                        return;
                    }
                    else{
                        correctOption = false;
                        cout << "Position not valid. Please introduce another valid number" << endl;
                        cin.clear();
                        cin.ignore();
                    }
                }while(!correctOption);

                if(infiniteGame){
                    deleteVectorPosition = positionsO[0];
                }

                updateBoard(board, optionSelected, turnX, turnO, correctPosition, infiniteGame, deleteVectorPosition);
                printBoard(board);  

                if(!correctPosition){
                    cout << "This position is already occupied. Please choose another one" << endl;
                }
                else{
                    positionsO.push_back(optionSelected);
                    if(infiniteGame){
                        positionsO.erase(positionsO.begin());
                    }
                    turnO = false;
                    turnX = true;
                }
                if(positionsO.size() == 3){
                    lineMade = checkLines(positionsO);
                    if(lineMade){
                        cout << "O is the Winner!!" << endl;
                        resetBoard(board);
                        positionsX.clear();
                        positionsO.clear();
                    }
                }
            }while(!correctPosition);

            if(!lineMade && positionsX.size()==3 && positionsO.size()==3 && !infiniteGame){
                cout << "The game has ended in a draw" << endl;
                cout << "Do you want to restart (r), leave (l) or continue (c) the game: ";
                cin >> continueOption;

                if(tolower(continueOption)=='r'){
                    continueGame = true;
                    resetBoard(board);
                    printBoard(board);
                    positionsX.clear();
                    positionsO.clear();
                }
                else if(tolower(continueOption)=='l'){
                    continueGame = false;
                    resetBoard(board);
                    positionsX.clear();
                    positionsO.clear();
                }
                else if(tolower(continueOption)=='c'){
                    infiniteGame = true;
                    turnO = false;
                    turnX = true;
                }
            }
        }

    }
}

int correspondantPosition(int i, int j){

    int position = 0;

    if(i == 1){
        if(j == 1){
            position = 1;
        }
        else if(j == 3){
            position = 2;
        }
        else if(j == 5){
            position = 3;
        }
    }
    else if(i == 3){
        if(j == 1){
            position = 4;
        }
        else if(j == 3){
            position = 5;
        }
        else if(j == 5){
            position = 6;
        }
    }
    else if(i == 5){
        if(j == 1){
            position = 7;
        }
        else if(j == 3){
            position = 8;
        }
        else if(j == 5){
            position = 9;
        }
    }

    return position;
}

int checkPossibleLines(vector<int>& positions){

    bool similar = false;
    int savePosition = 0;

    sortVectorPositions(positions);

    for(unsigned int i = 0; i < combinations.size() && !similar; i++){
        if(combinations[i][0] == positions[0]){
            if(combinations[i][1] == positions[1]){
                savePosition = combinations[i][2];
                similar = true;
            }
            else if(combinations[i][2] == positions[1]){
                savePosition = combinations[i][1];
                similar = true;
            }
        }
        else if(combinations[i][2] == positions[1]){
            if(combinations[i][1] == positions[0]){
                savePosition = combinations[i][0];
                similar = true;
            }
        }
    }
    
    return savePosition;
}

void firstTurnAI(char board[MAPSIZE][MAPSIZE], vector<int>& positionAI, vector<int>& positionPlayer, bool infiniteGame, int deleteVectorPosition){

    int position = 0;
    bool correctPosition = true;
    int savePosition = 0;
    bool completed = false;

    if(positionAI.size() == 0){
        do{
            position = (rand() % 9) + 1;
            updateBoard(board, position, false, true, correctPosition, infiniteGame, deleteVectorPosition);
            if(correctPosition){
                positionAI.push_back(position);
            }
        }while(!correctPosition);
    }
    else if(positionAI.size() == 1){
        for(int i = 1; i < MAPSIZE-1 && !completed; i++){
            for(int j = 1; j < MAPSIZE-1 && !completed; j++){
                if(board[i][j] == 'O'){
                    if(board[i][j+2] == ' '){ // right
                        updateBoard(board, correspondantPosition(i, j+2), false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(correspondantPosition(i, j+2));
                        completed = true;
                    }
                    else if(board[i][j-2] == ' '){ // left
                        updateBoard(board, correspondantPosition(i, j-2), false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(correspondantPosition(i, j-2));
                        completed = true;
                    }
                    else if(board[i-2][j] == ' '){ // up
                        updateBoard(board, correspondantPosition(i-2, j), false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(correspondantPosition(i-2, j));
                        completed = true;
                    }
                    else if(board[i+2][j] == ' '){ // down
                        updateBoard(board, correspondantPosition(i+2, j), false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(correspondantPosition(i+2, j));
                        completed = true;
                    }
                    else if(board[i-2][j+2] == ' '){ //up-right
                        updateBoard(board, correspondantPosition(i-2, j+2), false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(correspondantPosition(i-2, j+2));
                        completed = true;
                    }
                    else if(board[i-2][j-2] == ' '){ //up-left
                        updateBoard(board, correspondantPosition(i-2, j-2), false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(correspondantPosition(i-2, j-2));
                        completed = true;
                    }
                    else if(board[i+2][j+2] == ' '){ // down-right
                        updateBoard(board, correspondantPosition(i+2, j+2), false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(correspondantPosition(i+2, j+2));
                        completed = true;
                    }
                    else if(board[i+2][j-2] == ' '){ // down-left
                        updateBoard(board, correspondantPosition(i+2, j-2), false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(correspondantPosition(i+2, j-2));
                        completed = true;
                    }
                }
            }
        }
    }
    else if(positionAI.size() == 2){

        savePosition = checkPossibleLines(positionAI);
        int boardPosition1 = 0;
        int boardPosition2 = 0;
        transformPosition(savePosition, boardPosition1, boardPosition2);
        if(board[boardPosition1][boardPosition2] == ' '){
            updateBoard(board, savePosition, false, true, correctPosition, infiniteGame, deleteVectorPosition);
            positionAI.push_back(savePosition);
        }
        else if(board[boardPosition1][boardPosition2] != ' '){
            savePosition = checkPossibleLines(positionPlayer);
            if(savePosition == 0){
                do{
                    savePosition = (rand() % 9) + 1;
                    transformPosition(savePosition, boardPosition1, boardPosition2);
                }while(board[boardPosition1][boardPosition2] != ' ');
            }
            updateBoard(board, savePosition, false, true, correctPosition, infiniteGame, deleteVectorPosition);
            positionAI.push_back(savePosition);
        }
    }
    else if(positionAI.size() == 3 && infiniteGame){
        if(infiniteGame){
            deleteVectorPosition = positionAI[0];
            positionAI.erase(positionAI.begin());
        }

        savePosition = checkPossibleLines(positionAI);
        int boardPosition1 = 0;
        int boardPosition2 = 0;
        transformPosition(savePosition, boardPosition1, boardPosition2);
        if(board[boardPosition1][boardPosition2] == ' '){
            updateBoard(board, savePosition, false, true, correctPosition, infiniteGame, deleteVectorPosition);
            positionAI.push_back(savePosition);
        }
        else if(board[boardPosition1][boardPosition2] != ' '){
            savePosition = checkPossibleLines(positionPlayer);
            if(savePosition == 0){
                do{
                    savePosition = (rand() % 9) + 1;
                    transformPosition(savePosition, boardPosition1, boardPosition2);
                }while(board[boardPosition1][boardPosition2] != ' ');
            }
            updateBoard(board, savePosition, false, true, correctPosition, infiniteGame, deleteVectorPosition);
            positionAI.push_back(savePosition);
        }
    }
}

void secondTurnAI(char board[MAPSIZE][MAPSIZE], vector<int>& positionAI, vector<int>& positionPlayer, bool infiniteGame, int deleteVectorPosition){

    int position = 0;
    bool correctPosition = true;
    int savePosition = 0;
    bool stopLoop = false;

    int boardPosition1 = 0;
    int boardPosition2 = 0;

    if(positionAI.size() == 0){
        do{
            position = (rand() % 9) + 1;
            updateBoard(board, position, false, true, correctPosition, infiniteGame, deleteVectorPosition);
            if(correctPosition){
                positionAI.push_back(position);
            }
        }while(!correctPosition);
    }
    else if(positionAI.size() == 1){
        savePosition = checkPossibleLines(positionPlayer);
        // if there's already a value saved in savePosition, AI is not going to choose a good position
        transformPosition(savePosition, boardPosition1, boardPosition2);
        
        do{
            if(board[boardPosition1][boardPosition2] != ' '){
                savePosition = (rand() % 9) + 1;
                transformPosition(savePosition, boardPosition1, boardPosition2);
            }
        }while(board[boardPosition1][boardPosition2] != ' ');

        correctPosition = true;
        updateBoard(board, savePosition, false, true, correctPosition, infiniteGame, deleteVectorPosition);
        positionAI.push_back(savePosition);
    }
    else if(positionAI.size() == 2){

        savePosition = checkPossibleLines(positionAI);
        int boardPosition1 = 0;
        int boardPosition2 = 0;
        transformPosition(savePosition, boardPosition1, boardPosition2);
        if(savePosition != 0 && board[boardPosition1][boardPosition2] == ' '){
            updateBoard(board, savePosition, false, true, correctPosition, infiniteGame, deleteVectorPosition);
            positionAI.push_back(savePosition);
        }
        else{
            for(int i = 1; i < MAPSIZE - 1 && !stopLoop; i++){
                for(int j = 0; j < MAPSIZE - 1 && !stopLoop; j++){
                    if(board[i][j] == ' '){
                        position = correspondantPosition(i, j);
                        updateBoard(board, position, false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(position);
                        stopLoop = true;
                    }
                }
            }
        }
    }
    else if(positionAI.size() == 3 && infiniteGame){
        if(infiniteGame){
            deleteVectorPosition = positionAI[0];
            positionAI.erase(positionAI.begin());
        }

        savePosition = checkPossibleLines(positionAI);
        int boardPosition1 = 0;
        int boardPosition2 = 0;
        transformPosition(savePosition, boardPosition1, boardPosition2);
        if(savePosition != 0 && board[boardPosition1][boardPosition2] == ' '){
            updateBoard(board, savePosition, false, true, correctPosition, infiniteGame, deleteVectorPosition);
            positionAI.push_back(savePosition);
        }
        else{
            for(int i = 1; i < MAPSIZE - 1 && !stopLoop; i++){
                for(int j = 0; j < MAPSIZE - 1 && !stopLoop; j++){
                    if(board[i][j] == ' '){
                        position = correspondantPosition(i, j);
                        updateBoard(board, position, false, true, correctPosition, infiniteGame, deleteVectorPosition);
                        positionAI.push_back(position);
                        stopLoop = true;
                    }
                }
            }
        }
    }
}

void playIAGame(char board[MAPSIZE][MAPSIZE], vector<vector<int>> combinations){

    vector<int> positionPlayer;
    vector<int> positionAI;

    int optionSelected = 0;
    char continueOption;

    bool lineMade = false;
    bool continueGame = true;

    bool correctPosition = true;
    bool correctOption = false;

    bool turnPlayer = false;
    bool turnAI = false;

    bool infiniteGame = false;
    int deleteVectorPosition = 0;

    bool firstTurn = false;

    turnSelector(turnPlayer, turnAI);

    if(turnAI){
        firstTurn = true; // necessary for the AI method
    }

    printBoard(board);

    while(!lineMade && continueGame){
        if(turnPlayer){
            do{
                correctPosition = true;
                do{
                    cout << "Player turn (0 to leave): ";
                    cin >> optionSelected;
                    if (cin.fail()) {
                        cin.clear();
                        cin.ignore(1000, '\n');
                        cout << "Invalid input. Please enter a number between 1 and 9, or 0 to leave." << endl;
                        correctOption = false;
                    }
                    else if(optionSelected > 0 && optionSelected < 10){
                        correctOption = true;
                    }
                    else if(optionSelected == 0){
                        return;
                    }
                    else{
                        correctOption = false;
                        cout << "Position not valid. Please introduce another valid number" << endl;
                        cin.clear(); // if the user introduces a character the buffer is cleaned to avoid errors
                        cin.ignore();
                    }
                }while(!correctOption);

                if(infiniteGame){
                    deleteVectorPosition = positionPlayer[0];
                }

                updateBoard(board, optionSelected, true, false, correctPosition, infiniteGame, deleteVectorPosition);

                if(!correctPosition){
                    cout << "This position is already occupied. Please choose another one" << endl;
                }
                else{
                    positionPlayer.push_back(optionSelected);

                    if(infiniteGame){
                        positionPlayer.erase(positionPlayer.begin());
                    }

                    turnPlayer = false;
                    turnAI = true;
                }
                if(positionPlayer.size() == 3){
                    lineMade = checkLines(positionPlayer);
                    if(lineMade){
                        cout << "Player is the Winner!!" << endl;
                        resetBoard(board);
                        positionPlayer.clear();
                        positionAI.clear();
                    }
                }
            } while(!correctPosition);

            if(!lineMade && positionPlayer.size()==3 && positionAI.size()==3 && !infiniteGame){
                cout << "The game has ended in a draw" << endl;
                cout << "Do you want to restart (r), leave (l) or continue (c) the game: ";
                cin >> continueOption;

                if(tolower(continueOption)=='r'){
                    continueGame = true;
                    resetBoard(board);
                    printBoard(board);
                    positionPlayer.clear();
                    positionAI.clear();
                }
                else if(tolower(continueOption)=='l'){
                    continueGame = false;
                    resetBoard(board);
                    positionPlayer.clear();
                    positionAI.clear();
                }
                else if(tolower(continueOption)=='c'){
                    infiniteGame = true;
                    turnPlayer = false;
                    turnAI = true;
                    cout << "Hola";
                }
            }
        }
        else if(turnAI){
            if(positionAI.size() != 3){
                if(firstTurn){
                    firstTurnAI(board, positionAI, positionPlayer, infiniteGame, deleteVectorPosition);
                    printBoard(board);
                    turnAI = false;
                    turnPlayer = true;
                }
                else{
                    secondTurnAI(board, positionAI, positionPlayer, infiniteGame, deleteVectorPosition);
                    printBoard(board);
                    turnAI = false;
                    turnPlayer = true;
                }
            }
            else if(positionAI.size() == 3 && infiniteGame){
                if(firstTurn){
                    firstTurnAI(board, positionAI, positionPlayer, true, deleteVectorPosition);
                    printBoard(board);
                    turnAI = false;
                    turnPlayer = true;
                }
                else{
                    secondTurnAI(board, positionAI, positionPlayer, true, deleteVectorPosition);
                    printBoard(board);
                    turnAI = false;
                    turnPlayer = true;
                }
            }
            if(positionAI.size() == 3){
                lineMade = checkLines(positionAI);
                if(lineMade){
                    cout << "AI is the Winner!!" << endl;
                    resetBoard(board);
                    positionPlayer.clear();
                    positionAI.clear();
                }
            }
            if(!lineMade && positionPlayer.size()==3 && positionAI.size()==3 && !infiniteGame){
                cout << "The game has ended in a draw" << endl;
                cout << "Do you want to restart (r), leave (l) or continue (c) the game: ";
                cin >> continueOption;

                if(tolower(continueOption)=='r'){
                    continueGame = true;
                    resetBoard(board);
                    printBoard(board);
                    positionPlayer.clear();
                    positionAI.clear();
                }
                else if(tolower(continueOption)=='l'){
                    continueGame = false;
                    resetBoard(board);
                    positionPlayer.clear();
                    positionAI.clear();
                }
                else if(tolower(continueOption)=='c'){
                    infiniteGame = true;
                    turnAI = false;
                    turnPlayer = true;
                }
            }

        }
    }

}

void printMenu(){

    cout << endl <<"#################################\n"
                << "#                               #\n"
                << "#          TIC-TAC-TOE          #\n"
                << "#                               #\n"
                << "#        made by marcosbp       #\n"
                << "#                               #\n"
                << "#################################\n";


    cout << endl <<"\t(1) MULTIPLAYER" << endl
         << "\t(2) SINGLEPLAYER" << endl
         << "\t(3) RULES" << endl
         << "\t(4) EXIT" << endl << endl;

    cout << "Introduce an option: ";

}

void rules(){

    cout << "--------------------------------------------------------------------------------------------------\n";

    cout << endl
        << "1. GENERAL RULES" << endl << endl
        << "\t1.1 You play a 1v1 in a 3x3 board.\n"
        << "\t1.2 The first turn is randomly chosen.\n"
        << "\t1.3 You can choose between 9 different board positions (1-9).\n"
        << "\t1.4 Press 0 to leave the game at any moment.\n"
        << "\t1.5 Once both players have 3 pieces on the board, you will have to choose between three options.\n"
        << "\t\t1.5.1 Leave the game.\n"
        << "\t\t1.5.2 Restart the game.\n"
        << "\t\t1.5.3 Continue the game.\n"
        << "\t\t\t1.5.3.1 This option allows the players continue the game till one of them wins the battle.\n"
        << "\t\t\t1.5.3.2 When a new positions is selected, the first piece of the one's you have on the board\n" << "\t\t\t\twill change its position to the new one.\n\n"

        << "2. MULTIPLAYER" << endl << endl
        << "\t2.1 To play this gamemode you need two players in the same computer.\n"
        << "\t2.2 One player is identified as 'X' and the other as 'O'.\n\n"

        << "3. SINGLEPLAYER" << endl << endl
        << "\t3.1 Only one player is needed.\n"
        << "\t3.2 You play against an algorithm that simulates a real player who is trying to win.\n"
        << "\t3.3 You are identified as 'X'.\n\n";

    cout << "--------------------------------------------------------------------------------------------------\n\n";
}

int main(){

    srand(time(NULL)); // to generate a random number
    
    vector<int> positionsA;
    vector<int> positionsB;
    
    char option;
    char board[MAPSIZE][MAPSIZE]= {{'#','#','#','#','#','#','#'},
                                    {'#',' ','|',' ','|',' ','#'},
                                    {'#','-','-','-','-','-','#'},
                                    {'#',' ','|',' ','|',' ','#'},
                                    {'#','-','-','-','-','-','#'},
                                    {'#',' ','|',' ','|',' ','#'},
                                    {'#','#','#','#','#','#','#'}}; // board initialization

    do{
        printMenu();
        cin >> option;
        cin.ignore();

        switch(option){
            case '1': playGame2players(board, combinations); // playGame
                break;
            case '2': playIAGame(board, combinations); // play solo game
                break;
            case '3': rules(); // rules
                break;
            case '4': // exit the game
                break;
            default:
                break;
        }
    } while(option != '4');
    
    return 0;
}