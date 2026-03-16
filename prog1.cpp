#include <iostream>

using namespace std;

class Movie 
{
public:
    char title[50];
    char genre[20];
    int releasedYear;

    void display() 
	{
        cout << "Title: " << title << " | Genre: " << genre << " | Year: " << releasedYear << endl;
    }
};

int main() 
{
    Movie movies[2]; 

    cout << "--- Enter Movie Details (Use '_' instead of spaces) ---" << endl;
    for (int i = 0; i < 2; i++) 
	{
        cout << "Movie " << i + 1 << " Title: ";
        cin >> movies[i].title;
        cout << "Movie " << i + 1 << " Genre: ";
        cin >> movies[i].genre;
        cout << "Movie " << i + 1 << " Year: ";
        cin >> movies[i].releasedYear;
    }

    cout << "\n--- Movie List ---" << endl;
    for (int i = 0; i < 2; i++) 
	{
        movies[i].display();
    }

    return 0;
}

