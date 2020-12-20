#include <../gtest/gtest.h>
#include "ArrayList.h"


TEST(ArrList, TArrayList){
	ASSERT_NO_THROW(TArrayList<int> arrlist);
}

TEST(ArrList, NoTArrayList){
	ASSERT_ANY_THROW(TArrayList<int> arrlist(-1));
}

TEST(ArrList, TArrayListCOP){
	TArrayList<int> arrlist1(5);

	ASSERT_NO_THROW(TArrayList<int> arrlist2(arrlist1));
}

TEST(ArrList, TArrayListCoppy){
	TArrayList<int> arrlist1(5);
	arrlist1.PushFirst(1);
	TArrayList<int> arrlist2(arrlist1);
	
	EXPECT_EQ(arrlist1.GetFirst(), arrlist2.GetFirst());
}

TEST(ArrList, PushGetFirst){
	TArrayList<int> arrlist(3);

	arrlist.PushFirst(1);
	arrlist.PushFirst(2);
	arrlist.PushFirst(3);

	EXPECT_EQ(3, arrlist.GetFirst());
	EXPECT_EQ(2, arrlist.GetFirst());
	EXPECT_EQ(1, arrlist.GetFirst());
}

TEST(ArrList, GushGetLast){
	TArrayList<int> arrlist(3);

	arrlist.PushLast(1);
	arrlist.PushLast(2);
	arrlist.PushLast(3);

	EXPECT_EQ(3, arrlist.GetLast());
	EXPECT_EQ(2, arrlist.GetLast());
	EXPECT_EQ(1, arrlist.GetLast());
}

TEST(ArrList, Push){
	TArrayList<int> arrlist(5);

	arrlist.PushLast(1);
	arrlist.PushLast(2);
	arrlist.PushLast(3);
	arrlist.PushLast(4);
	arrlist.Push(3, 5);

	EXPECT_EQ(3, arrlist.Get(2));
	EXPECT_EQ(5, arrlist.Get(2));
}

TEST(ArrList, Get){
	TArrayList<int> arrlist(5);

	arrlist.PushLast(1);
	arrlist.PushLast(2);
	arrlist.PushLast(3);
	arrlist.PushLast(4);
	arrlist.PushLast(5);

	EXPECT_EQ(3, arrlist.Get(2));
	EXPECT_EQ(4, arrlist.Get(2));
}

TEST(ArrList, IsFull){
	TArrayList<int> arrlist(3);

	arrlist.PushLast(1);
	arrlist.PushLast(2);
	arrlist.PushLast(3);

	ASSERT_TRUE(arrlist.IsFull());
}

TEST(ArrList, NoIsFull){
	TArrayList<int> arrlist(3);

	arrlist.PushLast(1);
	arrlist.PushLast(2);

	ASSERT_FALSE(arrlist.IsFull());
}

TEST(ArrList, IsEmpty){
	TArrayList<int> arrlist(3);

	ASSERT_TRUE(arrlist.IsEmpty());
}

TEST(ArrList, NoIsEmpty){
	TArrayList<int> arrlist(3);

	arrlist.PushLast(1);
	arrlist.PushLast(2);
	arrlist.PushLast(3);

	ASSERT_FALSE(arrlist.IsEmpty());
}

TEST(ArrList, PushFirstIsFull){
	TArrayList<int> arrlist(3);

	arrlist.PushFirst(1);
	arrlist.PushFirst(2);
	arrlist.PushFirst(3);

	ASSERT_ANY_THROW(arrlist.PushFirst(4));
}

TEST(ArrList, PushLastIsFull){
	TArrayList<int> arrlist(3);

	arrlist.PushLast(1);
	arrlist.PushLast(2);
	arrlist.PushLast(3);

	ASSERT_ANY_THROW(arrlist.PushLast(4));
}

TEST(ArrList, GetFirstIsEmpty){
	TArrayList<int> arrlist(3);

	ASSERT_ANY_THROW(arrlist.GetFirst());
}

TEST(ArrList, GetLastIsEmpty){
	TArrayList<int> arrlist(3);

	ASSERT_ANY_THROW(arrlist.GetLast());
}

TEST(ArrList, PushIsFull) {
	TArrayList<int> arrlist(3);

	arrlist.PushFirst(1);
	arrlist.PushFirst(2);
	arrlist.PushFirst(3);

	ASSERT_ANY_THROW(arrlist.Push(1, 4));
}
TEST(ArrList, GetIsEmpty){
	TArrayList<int> arrlist(3);

	ASSERT_ANY_THROW(arrlist.Get(1));
}

