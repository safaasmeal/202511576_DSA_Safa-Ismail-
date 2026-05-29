
#define LIBRARYBOOK_H

#include <string>

class LibraryBook {
private:
    std::string bookID;
    std::string title;
    std::string author;
    std::string borrowerName;
    int daysBorrowed;
    bool isBorrowed; // true if borrowed, false if available

public:
    // Constructors & Destructor
    LibraryBook();
    LibraryBook(std::string id, std::string t, std::string a);
    ~LibraryBook();

    // Getters
    std::string getBookID() const;
    std::string getTitle() const;
    std::string getAuthor() const;
    std::string getBorrowerName() const;
    int getDaysBorrowed() const;
    bool getIsBorrowed() const;

    // Setters
    void setBookID(std::string id);
    void setTitle(std::string t);
    void setAuthor(std::string a);
    void setBorrowerName(std::string name);
    void setDaysBorrowed(int days);
    void setIsBorrowed(bool status);

    // Core Functionalities
    void borrowBook(std::string name, int days);
    void returnBook();
    double calculateFine() const;
    void displayBookDetails() const;

};
#endif
