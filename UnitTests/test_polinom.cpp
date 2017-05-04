#include "gtest\gtest.h"
#include "Polinom.h"

TEST(Polinom, can_create)
{
	ASSERT_NO_THROW(Polinom p);
}

TEST(Polinom, can_add_two_monoms)
{
	Polinom p;
	p.AddElement(monom(1, 111));
	p.AddElement(monom(2, 222));

	EXPECT_EQ(2, p[0].GetCoefficient());
	EXPECT_EQ(1, p[1].GetCoefficient());
}

//TEST(Polinom, can_simplify)
//{
//	Polinom p;
//	p.AddElement(monom(1, 111));
//	p.AddElement(monom(2, 222));
//	p.AddElement(monom(3, 333));
//	p.Simplify();
//
//	EXPECT_EQ(3, p[0].GetCoefficient());
//	EXPECT_EQ(2, p[1].GetCoefficient());
//	EXPECT_EQ(1, p[2].GetCoefficient());
//}

TEST(Polinom, can_add)
{
	Polinom p1;
	p1.AddElement(monom(1, 111));
	p1.AddElement(monom(2, 222));
	Polinom p2;
	p2.AddElement(monom(1, 111));
	p2.AddElement(monom(2, 222));
	Polinom res;
	res = p1 + p2;

	EXPECT_EQ(4, res[0].GetCoefficient());
	EXPECT_EQ(2, res[1].GetCoefficient());
}

TEST(Polinom, can_add_double) 
{
	Polinom p;
	p.AddElement(monom(0.5, 100));
	p = p + p;

	EXPECT_EQ(1, p.GetLength());
	EXPECT_EQ(1, p[0].GetCoefficient());
}

TEST(Polinom, can_dif)
{
	Polinom p1;
	p1.AddElement(monom(3, 111));
	p1.AddElement(monom(3, 222));
	Polinom p2;
	p2.AddElement(monom(1, 111));
	p2.AddElement(monom(2, 222));
	Polinom res;
	res = p1 - p2;

	EXPECT_EQ(1, res[0].GetCoefficient());
	EXPECT_EQ(2, res[1].GetCoefficient());
}

TEST(Polinom, can_minus_null) 
{
	Polinom p1;
	p1.AddElement(monom(2, 100));
	p1.AddElement(monom(3, 200));
	Polinom p2;
	p2.AddElement(monom(0, 100));
	Polinom res;
	res = p1 - p2;

	EXPECT_EQ(2, res.GetLength());
	EXPECT_EQ(3, res[0].GetCoefficient());
	EXPECT_EQ(2, res[1].GetCoefficient());
}

TEST(Polinom, can_multiply_polinoms)
{
	Polinom p1;
	p1.AddElement(monom(1, 111));
	p1.AddElement(monom(2, 222));
	Polinom p2;
	p2.AddElement(monom(1, 111));
	p2.AddElement(monom(2, 222));
	Polinom res;
	res = p1 * p2;

	EXPECT_EQ(4, res[0].GetCoefficient());
	EXPECT_EQ(4, res[1].GetCoefficient());
	EXPECT_EQ(1, res[2].GetCoefficient());
}

TEST(Polinom, can_multiply_polinom_double) 
{
	Polinom p;
	p.AddElement(monom(0.5, 100));
	Polinom res = p * p;

	EXPECT_EQ(1, res.GetLength());
	EXPECT_EQ(0.25, res[0].GetCoefficient());
	EXPECT_EQ(200, res[0].GetDegree());
}

TEST(Polinom, can_multiply_polinom_monom) 
{
	Polinom p;
	p.AddElement(monom(1, 100));
	p.AddElement(monom(2, 200));
	monom m(3, 100);
	Polinom res;
	res = p * m;

	EXPECT_EQ(2, res.GetLength());
	EXPECT_EQ(6, res[0].GetCoefficient());
	EXPECT_EQ(3, res[1].GetCoefficient());
	EXPECT_EQ(300, res[0].GetDegree());
	EXPECT_EQ(200, res[1].GetDegree());
}


TEST(Polinom, can_multiply_polinom_const) {
	Polinom p;
	p.AddElement(monom(1, 100));
	p.AddElement(monom(2, 200));
	monom m(2, 000); 
	Polinom res;
	res = p * m;

	EXPECT_EQ(2, res.GetLength());
	EXPECT_EQ(4, res[0].GetCoefficient());
	EXPECT_EQ(2, res[1].GetCoefficient());
	EXPECT_EQ(200, res[0].GetDegree());
	EXPECT_EQ(100, res[1].GetDegree());
}

TEST(Polinom, can_not_multiply_polinom_whith_large_monom) 
{
	Polinom p;
	p.AddElement(monom(1, 100));
	p.AddElement(monom(2, 200));
	monom m(3, 900);
	Polinom res; 

	EXPECT_ANY_THROW(res = p * m);
}
