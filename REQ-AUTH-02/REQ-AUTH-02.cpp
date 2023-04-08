#include "pch.h"
#include "CppUnitTest.h"

extern "C" int loginUser(char* username, char* password);

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

//REQ-AUTH-002: The User Authentication Module SHALL provide a function "loginUser()" 
//that takes the username and password as input parameters and returns a boolean 
//value indicating whether the login was successful or not. 

namespace REQAUTH02
{
	TEST_CLASS(REQAUTH02)
	{
	public:

		TEST_METHOD(AUTH_02_01)
		{
			//Test Case ID: AUTH-02-01
			//Test Case Description: Test the loginUser() function with valid username and password to ensure successful login. This is testing REQ-AUTH-002.
			//Testing Prerequisites: A registered user with a valid username and password.
			//Testing Steps: Call the "loginUser()" function with the valid username and password.
			//Verify that the function returns true, indicating successful login.
			//Input Data: Valid username and password.
			//Expected Results: Function returns true, indicating successful login.
			//Actual Result and Traceability: Function returns true, indicating successful login.
			//Pass/Fail: Pass

			char* username = "validuser";
			char* password = "validpassword";
			bool expected = true;
			bool actual = loginUser(username, password);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AUTH_02_02)
		{
			//Test Case ID: AUTH-02-02
			//Test Case Description: Test loginUser() function with invalid username and invalid password. This is testing REQ-AUTH-002.
			//Testing Prerequisites: User account does not exist in the system.
			//Testing Steps: Call the "loginUser()" function with an invalid username and valid password.
			//Verify that the function returns false, indicating unsuccessful login.
			//Input Data: Username: "invaliduser" Password: "password123"
			//Expected Results: Function returns false, indicating unsuccessful login.
			//Actual Result and Traceability: Function returns false, indicating unsuccessful login.
			//Pass/Fail: Pass

			char* username = "invaliduser";
			char* password = "password123";
			bool expected = false;
			bool actual = loginUser(username, password);
			Assert::AreEqual(expected, actual);
		}

		TEST_METHOD(AUTH_02_03)
		{
			//Test Case ID: AUTH-02-03
			//Test Case Description: Test loginUser() function with valid username and invalid password. This is testing REQ-AUTH-002.
			//Testing Prerequisites: User account already exists in the system.
			//Testing Steps: Call the "loginUser()" function with a valid username and invalid password.
			//Verify that the function returns false, indicating unsuccessful login.
			//Input Data: Username: "johndoe" Password: "wrongpassword"
			//Expected Results: The function should return False indicating unsuccessful login.
			//Actual Result and Traceability: The function returns False indicating unsuccessful login.
			//Pass/Fail: Pass

			char* username = "johndoe";
			char* password = "wrongpassword";
			bool expected = false;
			bool actual = loginUser(username, password);
			Assert::AreEqual(expected, actual);
		}
	};
}

