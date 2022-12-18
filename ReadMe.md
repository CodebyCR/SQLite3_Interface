# A simple SQLite3 interface

_Use a SQLite database for storing and retrieving data._

It's super easy to install:

Choose the command for your package manager:

```bash
brew install sqlite3
```
```bash
npm install sqlite3
```
```bash
sudo apt install sqlite3
```
```bash
sudo pacman -S sqlite3
```

... or download the binary from [sqlite.org](https://sqlite.org/download.html).

## Usage

I administrate my SQLite databases favored with this VSCode extension: [SQLite](https://marketplace.visualstudio.com/items?itemName=alexcvzz.vscode-sqlite)

## Example

### Create a database

```C++
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
```

### Insert data

```C++
    if(const auto insert_query =
            "INSERT INTO GRADES (ID, NAME, LNAME, AGE, ADDRESS, GRADE) "
            "VALUES (2, 'Paul', 'Brown', 32, 'California', 1 );";
            db.addEntry(insert_query)) {
        
        std::cerr << "Error in addEntry function." << std::endl;
    }
```

### Delete data

```C++
    if(const auto delete_query =
            "DELETE from GRADES where ID=2;";
            db.deleteEntry(delete_query)) {
        
        std::cerr << "Error in deleteEntry function." << std::endl;
    }
```


### Select data

```C++
    if(const auto select_query =
            "Select * from GRADES";
            db.selectData(select_query)) {
    
        std::cerr << "Error in selectData function." << std::endl;
    }
```


### Result of the example in [main.cpp](main.cpp)

```Text
Table created Successfully

After insert function:
2 Paul Brown 32 California 1 

After delete function:

Process finished with exit code 0
```


