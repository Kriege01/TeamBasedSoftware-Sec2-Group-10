#include "pch.h"
#include "CppUnitTest.h"

extern "C" int deleteUser(char* username);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//REQ-AUTH-005: The User Authentication Module SHOULD provide a function "deleteUser()" 
//that takes the username as an input parameter and returns a boolean value indicating 
//whether the user deletion was successful or not. 

namespace REQAUTH05
{
	TEST_CLASS(REQAUTH05)
	{
	public:

		TEST_METHOD(AUTH_05_01)
		{
			char username[] = "test_user";
			bool result = deleteUser(username);
			Assert::IsTrue(result);
		}

		TEST_METHOD(AUTH_05_02)
		{
			char username[] = "non_existent_user";
			bool result = deleteUser(username);
			Assert::IsFalse(result);
		}

		TEST_METHOD(AUTH_05_03)
		{
			char username[] = "";
			bool result = deleteUser(username);
			Assert::IsFalse(result);
		}

		TEST_METHOD(AUTH_05_04)
		{
			char username[] = "deleted_user";
			bool result = deleteUser(username);
			Assert::IsFalse(result);
		}
	};
}

