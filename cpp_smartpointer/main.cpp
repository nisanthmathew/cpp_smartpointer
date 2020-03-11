#include <QCoreApplication>
#include "mystring.h" //using mystring class to try out raw and smart pointers
#include <memory> // to use smart pointers
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    //raw pointer example
    {
        // Using a raw pointer -- not recommended.
        MyString* infinitywar = new MyString("Inspired by Marvel Comics."
                                             " Movie involves inifinty stones, time travel"
                                             "and main villian is Thanos.");

        // Use infinitywar...

        int string_size{infinitywar->getlength()};
        std::cout << "storage used by the string is: " << string_size*sizeof(char) << " byte/s" << std::endl;

        // Don't forget to delete!
        delete infinitywar;
    }

    //smart pointer - unique pointer example

    {
        // Declare a smart pointer on stack and pass it the raw pointer.
        std::unique_ptr<MyString> infinitywar{new MyString{"Thanos succeeds in killing of"
                                                           "half the living things in the universse "
                                                           "in the previous film. "
                                                           "Our heros are trying to undo it."}};


        //         std::unique_ptr<MyString> infinitywar2 = make_unique<MyString>("suggestion"); // from c++14

        // Use infinitywar...
        int string_size{infinitywar->getlength()};
        std::cout << "storage used by the string is: " << string_size*sizeof(char) << " bytes" << std::endl;


    } // infinitywar is deleted automatically here.

    //smart pointer shared pointer example

    {
        // Declare a smart pointer on stack and pass it the raw pointer.
        std::shared_ptr<MyString> endgame{new MyString{"Thanos succeds in killing of"
                                                       "half the living things in the universe."}};
        std::shared_ptr<MyString> infinitywarbackground{endgame};

        // Use the pointers...
        int NumberofMarvelMovies{endgame.use_count()};
        std::cout << "Marvel movies count: " << NumberofMarvelMovies << std::endl;

        // vector of chared pointers
        std::vector<std::shared_ptr<MyString>> MarvelMoviesCollection;
        MarvelMoviesCollection.push_back(endgame);
        MarvelMoviesCollection.push_back(infinitywarbackground);
        for(auto &Movies : MarvelMoviesCollection){
            std::cout << Movies.get()->getmystring() <<std::endl;
        }
        std::cout << "Marvel movies count: " << NumberofMarvelMovies << std::endl;

    } // end game, infinitywar and moviecollection are deleted automatically here.

    return a.exec();



}
