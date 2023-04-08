#include "pch.h"
#include "CppUnitTest.h"

extern "C" int registerUser(char*, char*);
extern "C" int updateUserPassword(char* username, char* newPassword);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//REQ-AUTH-004: The User Authentication Module SHOULD provide a function "updateUserPassword()" 
//that takes the username and new password as input parameters and returns a boolean value 
//indicating whether the password update was successful or not. 

namespace REQAUTH04
{
	TEST_CLASS(UpdateUserPasswordTests)
	{
	public:

		TEST_METHOD(Test_ValidUsernameAndNewPassword)
		{
			// Arrange
			char username[] = "john.doe";
			char password[] = "password123";
			char newPassword[] = "newpassword123";
			registerUser(username, password);

			// Act
			bool result = updateUserPassword(username, newPassword);

			// Assert
			Assert::IsTrue(result);
		}

		TEST_METHOD(Test_InvalidUsernameAndValidNewPassword)
		{
			// Arrange
			char username[] = "jane.doe";
			char newPassword[] = "newpassword123";

			// Act
			bool result = updateUserPassword(username, newPassword);

			// Assert
			Assert::IsFalse(result);
		}

		TEST_METHOD(Test_ValidUsernameAndInvalidNewPassword)
		{
			// Arrange
			char username[] = "john.doe";
			char password[] = "password123";
			char newPassword[] = "weak";
			registerUser(username, password);

			// Act
			bool result = updateUserPassword(username, newPassword);

			// Assert
			Assert::IsFalse(result);
		}

		TEST_METHOD(Test_ValidUsernameAndExistingPassword)
		{
			// Arrange
			char username[] = "john.doe";
			char password[] = "password123";
			registerUser(username, password);

			// Act
			bool result = updateUserPassword(username, password);

			// Assert
			Assert::IsFalse(result);
		}
	};
}
