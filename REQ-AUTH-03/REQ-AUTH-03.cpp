#include "pch.h"
#include "CppUnitTest.h"

extern "C" int checkUserExists(char* username);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//REQ-AUTH-003: The User Authentication Module SHALL provide a function "checkUserExists()" 
//that takes the username as an input parameter and returns a boolean value indicating 
//whether the user exists or not. 

namespace REQAUTH03
{
	TEST_CLASS(REQAUTH03)
	{
	public:

		TEST_METHOD(AUTH_03_01)
		{
			// Test the checkUserExists() function with a valid user to ensure that it correctly identifies an existing user. 
			// This is testing REQ-AUTH-003. 

			// Testing Prerequisites: A registered user with a valid username.
			char* existingUser = "johndoe";

			// Testing Steps: Call the "checkUserExists()" function with the username of the existing user.
			bool result = checkUserExists(existingUser);

			// Verify that the function returns true, indicating that the user exists.
			Assert::IsTrue(result);
		}

		TEST_METHOD(AUTH_03_02)
		{
			// Test the checkUserExists() function with invalid user to ensure that it correctly identifies a non-existing user. 
			// This is testing REQ-AUTH-003. 

			// Testing Prerequisites: No user with the given username should exist in the system.
			char* nonExistingUser = "nonexistinguser";

			// Testing Steps: Call the "checkUserExists()" function with a non-existing username.
			bool result = checkUserExists(nonExistingUser);

			// Verify that the function returns false, indicating that the user does not exist.
			Assert::IsFalse(result);
		}

		TEST_METHOD(AUTH_03_03)
		{
			// Test if the checkUserExists() function with empty string to ensure it returns false. 
			// This is testing REQ-AUTH-003. 

			// Testing Prerequisites: None.
			char* emptyUser = "";

			// Testing Steps: Call the function checkUserExists() with an empty string as input.
			bool result = checkUserExists(emptyUser);

			// Verify that the function returns false, indicating that the user does not exist.
			Assert::IsFalse(result);
		}

		TEST_METHOD(AUTH_03_04)
		{
			// Test if the checkUserExists() function returns False when a nullptr value is passed as input. 
			// This is testing REQ-AUTH-003. 

			// Testing Prerequisites: None.
			char* nullUser = nullptr;

			// Testing Steps: Call the function checkUserExists() with a nullptr value as input.
			bool result = checkUserExists(nullUser);

			// Verify that the function returns false, indicating that the user does not exist.
			Assert::IsFalse(result);
		}
	};
}

