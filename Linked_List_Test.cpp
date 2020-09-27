#include "pch.h"
#include "CppUnitTest.h"
#include "../Lab1_Linked_List_7/Linked_List.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace LinkedListTest
{
	TEST_CLASS(LinkedListTest)
	{
	public:
		
		TEST_METHOD(TestClassInit1)
		{
			size_t n = 10;
			int* arr = new int[n];
			for (size_t i = 0; i < n; i++)
				arr[i] = i * i;
			LinkedList* list = new LinkedList(arr, n);
			for (size_t i = 0; i < n; i++) {
				Assert::AreEqual(arr[i], list->at(i));
			}
		}
		TEST_METHOD(TestClassInit2) {
			LinkedList* list = new LinkedList();
			Assert::IsNull(list->head);
			Assert::IsNull(list->last);
			Assert::IsNull(list->cur);
		}
		TEST_METHOD(TestPushBack) {
			LinkedList* list = new LinkedList();
			list->push_back(5);
			Assert::AreEqual(5, list->at(list->get_size() - 1));
			Assert::IsNull(list->last->next);
		}
		TEST_METHOD(TestPushFront) {
			LinkedList* list = new LinkedList();
			list->push_front(3);
			Assert::AreEqual(3, list->at(0));
		}
		TEST_METHOD(TestPopBack) {
			LinkedList* list = new LinkedList();
			list->push_back(1);
			list->push_back(2);
			list->pop_back();
			Assert::AreEqual(1, list->at(list->get_size() - 1));
			Assert::AreNotEqual(2, list->at(list->get_size() - 1));
			Assert::IsNull(list->last->next);
			list->clear();
			Assert::ExpectException<exception>([list] { list->pop_back(); });
		}
		TEST_METHOD(TestPopFront) {
			LinkedList* list = new LinkedList();
			list->push_back(1);
			list->push_back(2);
			list->pop_front();
			Assert::AreEqual(2, list->at(0));
			Assert::AreNotEqual(1, list->at(0));
			list->clear();
			Assert::ExpectException<exception>([list] {list->pop_front();  });
		}
		TEST_METHOD(TestInsert) {
			LinkedList* list = new LinkedList();
			list->push_back(1);
			list->push_back(3);
			list->insert(2, 1);
			Assert::AreEqual(2, list->at(1));
			Assert::ExpectException<out_of_range>([list] {list->insert(10, 12); });
		}
		TEST_METHOD(TestAt) {
			int arr[] = { 1, 2, 3, 4, 5 };
			LinkedList* list = new LinkedList(arr, 5);
			Assert::AreEqual(arr[1], list->at(1));
			Assert::AreNotEqual(arr[3], list->at(2));
			Assert::ExpectException<out_of_range>([list] {list->at(30); });
		}
		TEST_METHOD(TestRemove) {
			int arr[] = { 1, 2, 3, 4, 5 };
			LinkedList* list = new LinkedList(arr, 5);
			list->remove(2);
			Assert::AreNotEqual(arr[2], list->at(2));
			Assert::AreEqual(arr[3], list->at(2));
			Assert::ExpectException<out_of_range>([list] {list->remove(15); });
		}
		TEST_METHOD(TestGetSize) {
			int arr[] = { 1, 2, 3, 4, 5 };
			LinkedList* list = new LinkedList(arr, 5);
			Assert::AreEqual(5, (int)list->get_size());
		}
		TEST_METHOD(TestPrintToConsole) {
			LinkedList* list = new LinkedList();
			Assert::ExpectException<exception>([list] {list->print_to_console(); });
		}
		TEST_METHOD(TestClear) {
			int arr[] = { 1, 2, 3, 4, 5 };
			LinkedList* list = new LinkedList(arr, 5);
			Assert::IsNotNull(list->head);
			list->clear();
			Assert::IsNull(list->head);
		}
		TEST_METHOD(TestSet) {
			int arr[] = { 1, 2, 3, 4, 5 };
			LinkedList* list = new LinkedList(arr, 5);
			list->set(3, 0);
			Assert::AreEqual(0, list->at(3));
			Assert::AreNotEqual(arr[3], list->at(3));
			Assert::ExpectException<out_of_range>([list] {list->set(20, 7); });
		}
		TEST_METHOD(TestIsEmpty) {
			int arr[] = { 1, 2, 3, 4, 5 };
			LinkedList* list = new LinkedList(arr, 5);
			Assert::IsFalse(list->isEmpty());
			list->clear();
			Assert::IsTrue(list->isEmpty());
		}
		TEST_METHOD(TestPushFrontList) {
			int arr1[] = { 1, 2, 3, 4, 5 };
			LinkedList* list = new LinkedList(arr1, 5);
			int arr2[] = { -3, -2, -1, 0 };
			LinkedList* temp_list = new LinkedList(arr2, 4);
			list->push_front(temp_list);
			Assert::AreNotEqual(arr1[0], list->at(0));
			Assert::AreEqual(arr2[0], list->at(0));
			temp_list->clear();
			Assert::ExpectException<exception>([list, temp_list] {list->push_front(temp_list); });
		}
	};
}
