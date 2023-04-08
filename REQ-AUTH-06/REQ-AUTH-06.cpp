#include "pch.h"
#include "CppUnitTest.h"
#include "UserAuthentication.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace REQAUTH06
{
	TEST_CLASS(REQAUTH06)
	{
	public:

		TEST_METHOD(AUTH_06_01)
		{
			// Arrange
			char filepath[] = "empty_users.txt";

			// Act
			User** users = readUsersFromFile(filepath);

			// Assert
			Assert::IsNull(users);
		}

		TEST_METHOD(AUTH_06_02)
		{
			// Arrange
			char filepath[] = "one_user.txt";

			// Act
			User** users = readUsersFromFile(filepath);

			// Assert
			Assert::AreEqual(1, num_users);
			Assert::AreEqual(std::string("username"), std::string(users[0]->username));
			Assert::AreEqual(std::string("password"), std::string(users[0]->password));

			// Clean up
			freeUsersArray(users);
		}

		TEST_METHOD(AUTH_06_03)
		{
			// Arrange
			char filepath[] = "multiple_users.txt";

			// Act
			User** users = readUsersFromFile(filepath);

			// Assert
			Assert::AreEqual(2, num_users);
			Assert::AreEqual(std::string("username1"), std::string(users[0]->username));
			Assert::AreEqual(std::string("password1"), std::string(users[0]->password));
			Assert::AreEqual(std::string("username2"), std::string(users[1]->username));
			Assert::AreEqual(std::string("password2"), std::string(users[1]->password));

			// Clean up
			freeUsersArray(users);
		}

		TEST_METHOD(AUTH_06_04)
		{
			// Arrange
			char filepath[] = "nonexistent_file.txt";

			// Act
			User** users = readUsersFromFile(filepath);

			// Assert
			Assert::IsNull(users);
		}
	};
}

