#include "pch.h"
#include "CppUnitTest.h"

extern "C" int registerUser(char*, char*);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//REQ-AUTH-001: The User Authentication Module SHALL provide a function "registerUser()" 
//that takes the username and password as input parameters and returns a boolean value 
//indicating whether the registration was successful or not. 

namespace REQAUTH01
{
	TEST_CLASS(REQAUTH01)
	{
	public:

		// Test Case ID: AUTH-01-01
		TEST_METHOD(AUTH0101_Test)
		{
			// Testing the registerUser() function with valid username and password to ensure successful registration. Testing REQ-AUTH-001.

			// Arrange
			char username[] = "validusername";
			char password[] = "validpassword";

			// Act
			int result = registerUser(username, password);

			// Assert
			Assert::AreEqual(1, result, L"Registration failed", LINE_INFO());
		}

		// Test Case ID: AUTH-01-02
		TEST_METHOD(AUTH0102_Test)
		{
			// Testing if registering a new user with an existing username returns false. Testing REQ-AUTH-001.

			// Arrange
			char existingUsername[] = "existinguser";
			char password[] = "newpassword";

			// Act
			int result = registerUser(existingUsername, password);

			// Assert
			Assert::AreEqual(0, result, L"Registration succeeded", LINE_INFO());
		}

		// Test Case ID: AUTH-01-03
		TEST_METHOD(AUTH0103_Test)
		{
			// Test if registering a new user with an invalid username and valid password returns false. Testing REQ-AUTH-001.

			// Arrange
			char invalidUsername[] = "user@name";
			char password[] = "testpassword";

			// Act
			int result = registerUser(invalidUsername, password);

			// Assert
			Assert::AreEqual(0, result, L"Registration succeeded", LINE_INFO());
		}

		// Test Case ID: AUTH-01-04
		TEST_METHOD(AUTH0104_Test)
		{
			// Test if registering a new user with valid username and an invalid password format returns false. Testing REQ-AUTH-001.

			// Arrange
			char username[] = "testuser";
			char invalidPassword[] = "pass";

			// Act
			int result = registerUser(username, invalidPassword);

			// Assert
			Assert::AreEqual(0, result, L"Registration succeeded", LINE_INFO());
		}
	};
}
