#include "pch.h"
#include "CppUnitTest.h"
/*
#include "UserAuthentication.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace REQAUTH07
{
	TEST_CLASS(REQAUTH07)
	{
	public:

		TEST_METHOD(AUTH_07_01)
		{
			char filepath[] = "/home/user/users.txt";
			User* users[2];
			users[0] = new User("John", "password1");
			users[1] = new User("Jane", "password2");

			Assert::IsTrue(writeUsersToFile(filepath, users));

			// Verify that the file contents are correct
			std::ifstream file(filepath);
			std::string line;
			std::getline(file, line);
			Assert::AreEqual(std::string("John,password1"), line);
			std::getline(file, line);
			Assert::AreEqual(std::string("Jane,password2"), line);

			// Clean up
			delete users[0];
			delete users[1];
			file.close();
			remove(filepath);
		}

		TEST_METHOD(AUTH_07_02)
		{
			char filepath[] = "/home/user/nonexistent.txt";
			User* users[2];
			users[0] = new User("John", "password1");
			users[1] = new User("Jane", "password2");

			Assert::IsFalse(writeUsersToFile(filepath, users));

			// Clean up
			delete users[0];
			delete users[1];
		}

		TEST_METHOD(AUTH_07_03)
		{
			char filepath[] = "/home/user/users.txt";
			User* users[1];

			Assert::IsTrue(writeUsersToFile(filepath, users, 0));

			// Verify that the file is empty
			std::ifstream file(filepath);
			std::string line;
			Assert::IsFalse(static_cast<bool>(std::getline(file, line)));

			// Clean up
			file.close();
			remove(filepath);
		}

		TEST_METHOD(AUTH_07_04)
		{
			char filepath[] = "/home/user/read_only.txt";
			User* users[2];
			users[0] = new User("John", "password1");
			users[1] = new User("Jane", "password2");

			// Make the file read-only
			std::ofstream file(filepath);
			file.close();
			_chmod(filepath, _S_IREAD);

			Assert::IsFalse(writeUsersToFile(filepath, users));

			// Clean up
			delete users[0];
			delete users[1];
			_chmod(filepath, _S_IWRITE);
			remove(filepath);
		}

		TEST_METHOD(AUTH_07_05)
		{
			char filepath[] = "/home/user/users.txt";
			User* users[2];
			users[0] = new User("John");
			users[1] = new User("Jane", "");

			Assert::IsFalse(writeUsersToFile(filepath, users));

			// Verify that the file contents are unchanged
			std::ifstream file(filepath);
			std::string line;
			std::getline(file, line);
			Assert::IsTrue(line.empty());
			std::getline(file, line);
			Assert::IsTrue(line.empty());

			// Clean up
			delete users[0];
			delete users[1];
			file.close();
			remove(filepath);
		}
	};
}
*/