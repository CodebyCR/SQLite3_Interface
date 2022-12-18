//
// Created by Christoph Rohde on 18.12.22.
//

#pragma once

#include <iostream>
#include <sqlite3.h>

class SQLite_DB {

private:
    sqlite3 *DB{};
    char *messageError = nullptr;
    sqlite3_stmt *res = nullptr;
    int exit = 0;
    int cols = 0;
    int result = 0;

public:
    SQLite_DB() = delete;

    explicit SQLite_DB(const char* database) {
        exit = sqlite3_open(database, &DB);

        if (exit) {
            std::cerr << "Error open DB " << sqlite3_errmsg(DB) << std::endl;
        }
    }

    ~SQLite_DB() = default;


    auto createTable(const char* table_query) -> int8_t
    {

        try {

            /* An open database, SQL to be evaluated, Callback function, 1st argument to callback, Error msg written here */
            exit = sqlite3_exec(DB, table_query, nullptr, nullptr, &messageError);
            if (exit != SQLITE_OK) {
                std::cerr << "Error in createTable function." << std::endl;
                sqlite3_free(messageError);
            }
            else {
                std::cout << "Table created Successfully" << std::endl;

            }

        }
        catch (const std::errc& e)
        {
            std::cerr << make_error_code(e) << std::endl;
            sqlite3_close(DB);
        }

        return 0;
    }

    auto selectData(const char *const select_query) ->int8_t
    {

        try {

            exit = sqlite3_prepare_v2(DB, select_query, -1, &res, nullptr);
            if (exit != SQLITE_OK) {
                std::cerr << "Error in selectData function." << std::endl;
                sqlite3_free(messageError);
                sqlite3_close(DB);
            }

            cols = sqlite3_column_count(res);
            result = 0;

            while (true) {
                result = sqlite3_step(res);

                if (result == SQLITE_ROW) {
                    for (int col = 0; col < cols; col++) {
                        std::cout << sqlite3_column_text(res, col) << " ";
                    }
                    std::cout << std::endl;
                }

                if (result == SQLITE_DONE || result == SQLITE_ERROR) {
                    break;
                }
            }

        }
        catch (const std::errc& e)
        {
            std::cerr << make_error_code(e) << std::endl;
        }

        return 0;
    }

    auto addEntry(const char* insert_query) ->int8_t {

        try {

            exit = sqlite3_exec(DB, insert_query, nullptr, nullptr, &messageError);
            if (exit != SQLITE_OK) {
                std::cerr << "Error in addEntry function." << std::endl;
                sqlite3_free(messageError);
                sqlite3_close(DB);
            }
//        else {
//            std::cout << "Records created Successfully" << std::endl;
//
//        }

        }
        catch (const std::errc& e)
        {
            std::cerr << make_error_code(e) << std::endl;
            return 1;
        }

        return 0;
    }

};
