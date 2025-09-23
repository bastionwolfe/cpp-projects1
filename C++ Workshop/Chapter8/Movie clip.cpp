// video clip class
//1. create videoclip class outline
//2. create member variables for length and name
//3. create a constructor that defaults length and name
//4. write a constructor that sets video length and name
//5. create a data char array and data size member and initialize them in constructor
//6. create a copy constructor that correctly handles the copying of data array
//7. create a copy assignment overload that handles the copying of data array
//8. write a deconstructor to delete the allocated data array
//9. update main to output 3 movies
#include <iostream>

class Movie {
public:
    float m_lengthInMinutes;
    std::string m_movieName;
    std::string m_directorName;
    int m_dataSize;
    char * m_data;
    Movie(float lengthInMinutes = 0.0f, std::string movieName = "not set",std::string directorName = "not set", const char * data = NULL) {
        m_lengthInMinutes = lengthInMinutes;
        m_movieName = movieName;
        m_directorName = directorName;
        
        m_dataSize = strlen(data);
        m_data = new char[m_dataSize +1];
        strcpy(m_data, data);
    }
    
    ~Movie(){
        delete[] m_data;
    }
    
    void SetData(float lengthInMinutes = 0.0f, std::string movieName = "not set",std::string directorName = "not set", const char * newData = NULL) {
        m_lengthInMinutes = lengthInMinutes;
        m_movieName = movieName;
        m_directorName = directorName;
        
        delete[] m_data;
        m_dataSize = strlen(newData);
        m_data = new char[m_dataSize + 1];
        strcpy(m_data, newData);
    }
    
    Movie(const Movie& movie) {
        m_lengthInMinutes = movie.m_lengthInMinutes;
        m_movieName = movie.m_movieName;
        m_directorName = movie.m_directorName;
        m_dataSize = movie.m_dataSize;
        
        m_data = new char[m_dataSize +1];
        strcpy(m_data, movie.m_data);
    }
    
    Movie& operator =(const Movie& movie) {
        if(this != &movie) {
            m_lengthInMinutes = movie.m_lengthInMinutes;
            m_movieName = movie.m_movieName;
            m_directorName = movie.m_directorName;
            m_dataSize = movie.m_dataSize;
            
            char* newData = new char[m_dataSize +1];
            strcpy(newData, movie.m_data);
            delete[] m_data;
            m_data = newData;
        }
        return *this;
    }
};

int main() {
    Movie movie(128.0f, "Weapons", "Zach Cregger", "f651270d6011098375db09912b03e5e7");
    Movie movie2 = movie;
    Movie movie3 = movie;
    movie2.SetData(140.0f, "Revenge of the Sith", "Goerge Lucas", "db6fd7d74393b375344010a0c9cc4535");
    movie3.SetData(99.0f, "Grand Budapest Hotel", "Wes Anderson", "aeaiofj92099348f09v8jq4oi4gv91l43");
    std::cout << "Movie 1" << std::endl;
    std::cout << "Director - " << movie.m_directorName << std::endl;
    std::cout << "Movie Name = " << movie.m_movieName << std::endl;
    std::cout << "Movie Length = " << movie.m_lengthInMinutes << std::endl;
    std::cout << "Track Data - " << movie.m_data << std::endl;
    std::cout << "Movie 2" << std::endl;
    std::cout << "Director - " << movie2.m_directorName << std::endl;
    std::cout << "Movie Name = " << movie2.m_movieName << std::endl;
    std::cout << "Movie Length = " << movie2.m_lengthInMinutes << std::endl;
    std::cout << "Movie Data - " << movie2.m_data << std::endl;
    std::cout << "Movie 3" << std::endl;
    std::cout << "Director - " << movie3.m_directorName << std::endl;
    std::cout << "Movie Name = " << movie3.m_movieName << std::endl;
    std::cout << "Movie Length = " << movie3.m_lengthInMinutes << std::endl;
    std::cout << "Movie Data - " << movie3.m_data << std::endl;
    
    return 0;
}
    
