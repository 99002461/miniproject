#include <iostream>
#include <limits>
#include <thread>
#include <chrono>

#include "book.h"
#include "member.h"
#include "store.h"
#include "util.h"

using namespace std;

void banner();
void menuHeader();
void help();
int getaction();

void addNewMember(Store *store);
void addNewBook(Store *store);
void borrowBookToMember(Store *store);
void takeBackBookFromMember(Store *store);
void listMemberBorrowedBooks(Store *store);
void listBooks(Store *store);
void listMembers(Store *store);

int main()
{
    auto store = new Store();

    banner();

    while (true)
    {
        help();
        int action = 0;
        while ((action = getaction()) == -1)
        {
            error("Invalid input.");
            error("Just enter number of the option you want.");
            help();
        }

        println();

        switch (action)
        {
        case 0:
        {
            exit(0);
        }
        case 1:
        {
            addNewMember(store);
            break;
        }
        case 2:
        {
            addNewBook(store);
            break;
        }
        case 3:
        {
            borrowBookToMember(store);
            break;
        }
        case 4:
        {
            takeBackBookFromMember(store);
            break;
        }
        case 5:
        {
            listMemberBorrowedBooks(store);
            break;
        }
        case 6:
        {
            listBooks(store);
            break;
        }
        case 7:
        {
            listMembers(store);
            break;
        }
        default:
            break;
        }
        
        // sleeps for 3 seconds before reprinting help
        {
            this_thread::sleep_for(chrono::seconds(3));
        }
    }

    return 0;
}

void banner()
{
    println();
    println(yellow("****************************************************"));
    println(yellow("*                                                  *"));
    println(yellow("*        Car Inventory Management App              *"));
    println(yellow("*                                                  *"));
    println(yellow("****************************************************"));
}

void menuHeader()
{
    cout << endl
         << endl
         << endl;
    println(red("****************************************************"));
}

void help()
{
    menuHeader();
    println("Choose one the following options:");
    println("[ " + yellow("1") + " ] " + "Add a new Car driver");
    println("[ " + yellow("2") + " ] " + "Add a new Car to library");
    println("[ " + yellow("3") + " ] " + "Borrow a Car to car driver");
    println("[ " + yellow("4") + " ] " + "Take-back a Car from a car diver");
    println("[ " + yellow("5") + " ] " + "Show a list of borrowed Cars by a car Drivers");
    println("[ " + yellow("6") + " ] " + "Show a list of Car in the library");
    println("[ " + yellow("7") + " ] " + "Show a list of car driver in the library");
    println("[ " + grey("0") + " ] " + "Exit");
    cout << endl;
}
println();
println();
println();


int getaction()
{
    auto action = promptInt("What can i do for you:");
    if (cin.fail() || action > 7 || action < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        return -1;
    }
    return action;
}

void addNewMember(Store *store)
{
    string firstName, lastName, id;
    uint entranceYear;

    info("Enter new car drivers details:");

    firstName = promptString("First Name:");
    lastName = promptString("Last Name:");
    id = promptString("driving licence number:");
    entranceYear = (uint)promptInt("Entrance Year:");

    if (store->memberExists(id))
    {
        error("car driver with DL number (" + yellowBold(id) + ") already registered.");
        return;
    }

    auto member = new Member(id);
    member->setEntranceYear(entranceYear)
        ->setFirstName(firstName)
        ->setLastName(lastName)
        ->setId(id);

    store->addMember(member);

    println();
    ok("New Car driver with following information was added successfully:");
    printNewMemberInformation(member);
}

void addNewBook(Store *store)
{
    string name, author, isbn;
    uint publishYear, total;

    info("Enter new car's information:");

    name = promptString("Name:");
    author = promptString("manufacturer:");
    isbn = promptString("Licence plate detail:");
    publishYear = (uint)promptInt("Registered Year:");
    total = (uint)promptInt("Total Number:");

    if (store->bookExists(isbn))
    {
        error("Car with licence (" + yellowBold(isbn) + ") already registered.");
        return;
    }

    auto book = new Book();
    book->setName(name)
        ->setAuthor(author)
        ->setISBN(isbn)
        ->setPublishYear(publishYear)
        ->setTotal(total);

    store->addBook(book);

    println();
    ok("New Car with following information was added successfully:");
    printNewBookInformation(book);
}

void borrowBookToMember(Store *store)
{
    info("Enter requested items to Rent a Car:");

    auto isbn = promptString("Enter Car with Licence plate detail:");
    auto book = store->findBookByISBN(isbn);
    if (book == NULL)
    {
        error("Could not find Car with registered Licence plate detail.");
        return;
    }

    if (!book->canBeBorrowed())
    {
        error("All Cars have been Rented.");
        return;
    }

    auto memberId = promptString("Enter Car driver ID:");
    auto member = store->findMemberById(memberId);
    if (member == NULL)
    {
        error("Car driver with entered ID is not registerd.");
        return;
    }

    if (!book->canBeBorrowedTo(member))
    {
        error("Car Driver has already rented this Car.");
        return;
    }

    book->borrowTo(member);

    ok("Car with License plate detail (" + yellowBold(book->getISBN()) + ")");
    ok("has been successfully rented by car driver with DL number (" + yellowBold(member->getId()) + ").");

    string s = "";
    if (book->getRemainingCount() > 1)
    {
        s = "s";
    }

    ok("Number of remaining Car" + s + ": " + yellowBold(to_string(book->getRemainingCount())));

    return;
}

void takeBackBookFromMember(Store *store)
{
    info("Enter requested items to take back a book:");

    auto memberId = promptString("Enter Car driver DL number:");
    auto member = store->findMemberById(memberId);
    if (member == NULL)
    {
        error("Car with entered DL number is not registerd.");
        return;
    }

    auto isbn = promptString("Enter Car License plate detail:");
    auto book = store->findBookByISBN(isbn);
    if (book == NULL)
    {
        error("Could not find teh Car with entered License plate detail.");
        return;
    }

    if (!member->hasBorrowedBook(book))
    {
        error("Car was not Retented to Car driver.");
        return;
    }

    book->takeBackFrom(member);

    ok("Car with Lincense plate detail (" + yellowBold(book->getISBN()) + ")");
    ok("has been successfully taken back from Car driver  with DL Number (" + yellowBold(member->getId()) + ").");
    ok("Number of Car in library:" + yellowBold(to_string(book->getRemainingCount())));

    return;
}

void listMemberBorrowedBooks(Store *store)
{
    info("Enter requested items to see a list of Cars rented by a car driver:");

    auto memberId = promptString("Enter Car driver DL number:");
    auto member = store->findMemberById(memberId);
    if (member == NULL)
    {
        error("Car driver with entered DL number is not registerd.");
        return;
    }

    println();
    info("Car driver with DL number (" + yellowBold(member->getId()) + ") has rented " + yellowBold(to_string(member->getBorrowedBooksCount())) + " cars.");

    auto books = member->getBorrowedBooks();
    if (books.size() == 0)
    {
        println();
        return;
    }

    info("List of Cars:");
    for (auto book = books.begin(); book != books.end(); book++)
    {
        printBorrowedBookInformation(*book);
    }
    println();
}

void listBooks(Store *store)
{
    auto books = store->getBooks();

    if (books.size() == 0)
    {
        info("No car has been registered yet.");
        println();
        return;
    }

    string plural = "";
    if (books.size() > 1)
    {
        plural = "s";
    }

    info("(" + yellowBold(to_string(books.size())) + ") car" + plural + " has been registered in the library.");
    info("Listing all Cars:");

    for (auto book = books.begin(); book != books.end(); book++)
    {
        printRegisteredBookInformation(*book);
        println();
    }
}

void listMembers(Store *store)
{
    auto members = store->getMembers();
    if (members.size() == 0)
    {
        info("No Car Driver has been registered yet.");
        println();
        return;
    }

    string plural = "";
    if (members.size() > 1)
    {
        plural = "s";
    }

    info("(" + yellowBold(to_string(members.size())) + ") Car driver" + plural + " has been registered in the library.");
    info("Listing all:");

    for (auto member = members.begin(); member != members.end(); member++)
    {
        printRegisteredMemberInformation(*member);
        println();
    }
}
