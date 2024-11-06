#include <iostream>
#include <fstream>
#include <filesystem>
#include <string>

using namespace std;
using namespace std::filesystem;

void createDirectory(const path &currentDir)
{
    string folderName;
    cout << "Enter the name of the directory to create: ";
    getline(cin, folderName);
    path newDir = currentDir / folderName;

    if (create_directory(newDir))
    {
        cout << "Directory created: " << newDir << endl;
    }
    else
    {
        cout << "Not created, it may exist." << endl;
    }
}

void displayFiles(const path &directory)
{
    if (exists(directory) && is_directory(directory))
    {
        cout << "\nContents of directory: " << directory << "\n";
        for (const auto &entry : directory_iterator(directory))
        {
            cout << (entry.is_directory() ? "[DIR] " : "[FILE] ");
            cout << entry.path().filename().string() << "\n";
        }
    }
    else
    {
        cout << "Directory does not exist.\n";
    }
}

void changeDirectory(path &currentDir)
{
    string newDir;
    cout << "Enter the directory to navigate to (.. for parent): ";
    getline(cin, newDir);
    path targetDir = currentDir / newDir;

    if (newDir == "..")
    {
        targetDir = currentDir.parent_path();
    }

    if (exists(targetDir) && is_directory(targetDir))
    {
        currentDir = targetDir;
        cout << "Changed to directory: " << currentDir << endl;
    }
    else
    {
        cout << "Directory does not exist.\n";
    }
}

void copyFile(const path &currentDir)
{
    string sourceFile, destFile;
    cout << "Enter the source file name (within current directory): ";
    getline(cin, sourceFile);
    cout << "Enter the destination file name or path: ";
    getline(cin, destFile);

    path sourcePath = currentDir / sourceFile;
    path destPath = currentDir / destFile;

    if (exists(sourcePath) && is_regular_file(sourcePath))
    {

        if (exists(destPath))
        {
            char overwrite;
            cout << "Destination file already exists. Do you want to overwrite it? (y/n): ";
            cin >> overwrite;
            cin.ignore();
            if (overwrite != 'y' && overwrite != 'Y')
            {
                cout << "File not copied.\n";
                return;
            }
        }

        copy(sourcePath, destPath);
        cout << "File copied successfully to " << destPath << "\n";
    }
    else
    {
        cout << "Error copying file. Source file does not exist.\n";
    }
}

void moveFile(const path &currentDir)
{
    string sourceFile, destFile;
    cout << "Enter the source file name (within current directory): ";
    getline(cin, sourceFile);
    cout << "Enter the destination file name or path: ";
    getline(cin, destFile);

    path sourcePath = currentDir / sourceFile;
    path destPath = currentDir / destFile;

    if (exists(sourcePath) && is_regular_file(sourcePath))
    {
        if (exists(destPath))
        {
            char overwrite;
            cout << "Destination file already exists. Do you want to overwrite it? (y/n): ";
            cin >> overwrite;
            cin.ignore();
            if (overwrite != 'y' && overwrite != 'Y')
            {
                cout << "File not moved.\n";
                return;
            }
        }

        rename(sourcePath, destPath);
        cout << "File moved successfully to " << destPath << "\n";
    }
    else
    {
        cout << "Error moving file. Source file does not exist.\n";
    }
}

int main()
{
    path currentDir = current_path();
    int choice;

    do
    {
        cout << "\nCurrent Directory: " << currentDir << endl;
        cout << "File Manager Options:" << endl;
        cout << "1. Display Files" << endl;
        cout << "2. Change Directory" << endl;
        cout << "3. Create Directory" << endl;
        cout << "4. Copy File" << endl;
        cout << "5. Move File" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore(); //

        switch (choice)
        {
        case 1:
            displayFiles(currentDir);
            break;
        case 2:
            changeDirectory(currentDir);
            break;
        case 3:
            createDirectory(currentDir);
            break;
        case 4:
            copyFile(currentDir);
            break;
        case 5:
            moveFile(currentDir);
            break;
        case 6:
            cout << "Exiting File Manager." << endl;
            break;
        default:
            cout << "Invalid choice. Try again." << endl;
            break;
        }
    } while (choice != 6);

    return 0;
}
