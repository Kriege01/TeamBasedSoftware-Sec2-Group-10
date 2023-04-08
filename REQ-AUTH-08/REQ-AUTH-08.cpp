#include "pch.h"
#include "CppUnitTest.h"
/*
extern "C" void freeUserMemory(char** users, int numUsers);


using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace REQAUTH08
{
    TEST_CLASS(REQAUTH08)
    {
    public:
        TEST_METHOD(AUTH_08_01)
        {
            // Initialize the user authentication module and retrieve user information from a file
            // ...

            const int numUsers = 5;
            char** userInfo = new char* [numUsers] {
                "user1", "user2", "user3", "user4", "user5"
            };

            // Call the function to be tested with a valid multi-dimensional array containing user information
            char** users = new char* [numUsers];
            for (int i = 0; i < numUsers; i++)
            {
                users[i] = new char[128];
                strcpy_s(users[i], 128, userInfo[i]);
            }
            bool success = freeUserMemory(users, numUsers);

            // Assert that the function successfully freed the dynamically allocated memory
            Assert::IsTrue(success);

            // Deallocate the memory used for testing
            for (int i = 0; i < numUsers; i++)
            {
                delete[] users[i];
            }
            delete[] users;
            delete[] userInfo;
        }

        TEST_METHOD(AUTH_08_02)
        {
            // Call the function to be tested with an empty multi-dimensional array
            char** users = new char* [0];
            bool success = freeUserMemory(users, 0);

            // Assert that the function successfully freed the dynamically allocated memory
            Assert::IsTrue(success);

            // Deallocate the memory used for testing
            delete[] users;
        }

        TEST_METHOD(AUTH_08_03)
        {
            // Call the function to be tested with a null pointer
            char** users = nullptr;
            bool success = freeUserMemory(users, 0);

            // Assert that the function failed to free memory due to a null pointer
            Assert::IsFalse(success);
        }

        TEST_METHOD(AUTH_08_04)
        {
            // Call the function to be tested with an invalid input (e.g., a string instead of a multi-dimensional array)
            char** users = new char* [1];
            users[0] = new char[128];
            strcpy_s(users[0], 128, "invalid input");
            bool success = freeUserMemory(users, 1);

            // Assert that the function failed to free memory due to an invalid input
            Assert::IsFalse(success);

            // Deallocate the memory used for testing
            delete[] users[0];
            delete[] users;
        }
    };
}

*/