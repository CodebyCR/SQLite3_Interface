#include <iostream>
#include "SQLite_Database/SQLite_DB.hpp"


int main() {

    auto database = "/Users/christoph_rohde/Desktop/TEST.db";

    auto db = SQLite_DB(database);


    if(const auto create_query =
            "CREATE TABLE IF NOT EXISTS GRADES("
            "ID INTEGER PRIMARY KEY AUTOINCREMENT, "
            "NAME      TEXT NOT NULL, "
            "LNAME     TEXT NOT NULL, "
            "AGE       INT  NOT NULL, "
            "ADDRESS   CHAR(50), "
            "GRADE     CHAR(1) );";
            db.createTable(create_query)) {

        std::cerr << "Error in createTable function." << std::endl;
    }

    if(const auto select_query =
            "Select * from GRADES";
            db.selectData(select_query)) {

        std::cerr << "Error in selectData function." << std::endl;
    }


    if(const auto insert_query =
            "INSERT INTO GRADES (ID, NAME, LNAME, AGE, ADDRESS, GRADE) "
            "VALUES (2, 'Paul', 'Brown', 32, 'California', 1 );";
            db.addEntry(insert_query)) {

        std::cerr << "Error in addEntry function." << std::endl;
    }

    std::cout << "\nAfter insert function:" << std::endl;
    if(const auto select_query =
            "Select * from GRADES";
            db.selectData(select_query)) {

        std::cerr << "Error in selectData function." << std::endl;
    }


    if(const auto delete_query =
            "DELETE from GRADES where not ID=1;";
            db.addEntry(delete_query)) {

        std::cerr << "Error in addEntry function." << std::endl;
    }

    std::cout << "\nAfter delete function:" << std::endl;
    if(const auto select_query =
            "Select * from GRADES";
            db.selectData(select_query)) {

        std::cerr << "Error in selectData function." << std::endl;
    }


    return 0;
}