#include "gtest\gtest.h"
#include "Monom.h"

TEST(monom, can_cteate_monom)
{
	ASSERT_NO_THROW(monom m(1, 111));
}

TEST(monom, can_set_and_get_CD)
{
	monom m;
	m.SetCoefficient(1);
	m.SetDegree(111);
	EXPECT_EQ(1, m.GetCoefficient());
	EXPECT_EQ(111, m.GetDegree());
}

TEST(monom, can_compare_1)
{
	monom m1(1, 111);
	monom m2(1, 111);
	EXPECT_TRUE(m1 == m2);
}

TEST(monom, cam_compare_2)
{
	monom m1(1, 111);
	monom m2(1, 222);
	EXPECT_FALSE(m1 == m2);
}

TEST(monom, can_compare_3)
{
	monom m1(1, 111);
	monom m2(1, 222);
	EXPECT_TRUE(m1 <m2);
	EXPECT_FALSE(m1 > m2);
}

TEST(monom, can_add)
{
	monom m1(1, 111);
	monom m2(1, 111);
	monom res = m1 + m2;
	EXPECT_EQ(2, res.GetCoefficient());
	EXPECT_EQ(111, res.GetDegree());
}

TEST(monom, can_multiply)
{
	monom m1(1, 111);
	monom m2(2, 111);
	monom res = m1*m2;
	EXPECT_EQ(2, res.GetCoefficient());
	EXPECT_EQ(222, res.GetDegree());
}

TEST(Monom, can_not_multiply_whith_large_degrees) {
	monom m1(3, 909);
	monom m2(2, 999);
	monom res;
	ASSERT_ANY_THROW(res = m1*m2);
}


