namespace UnitTestLab4
{
    [TestClass]
    public class UnitTest1
    {
        [TestMethod]
        [ExpectedException(typeof(ArgumentNullException))]
        public void TestCtor1()
        {
            Matrix mat = new Matrix(3, 3, null);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException))]
        public void TestCtor2()
        {
            int[,] arr = new int[3, 3];
            Matrix mat = new Matrix(-1, 3, arr);
        }
        [TestMethod]
        public void TestCtor3()
        {
            int[,] arr = new int[3, 3];
            Matrix mat = new Matrix(3, 3, arr);
            Assert.IsNotNull(mat);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void TestPlus1()
        {
            int[,] arr = new int[3, 3];
            Matrix mat = new Matrix(3, 3, arr);
            int[,] arr2 = new int[4, 5];
            Matrix mat2 = new Matrix(4, 5, arr2);
            Matrix res = mat + mat2;
        }
        [TestMethod]
        public void TestPlus2()
        {
            int[,] arr = new int[3, 3];
            int[,] arr2 = new int[3, 3];
            int[,] arr_exp = new int[3, 3];
            for(int i = 0; i < 3; i++)
            {
                for(int j = 0; j < 3; j++)
                {
                    arr[i, j] = 1;
                    arr2[i, j] = 1;
                    arr_exp[i, j] = 2;
                }
            }
            Matrix mat = new Matrix(3, 3, arr);
            Matrix mat2 = new Matrix(3, 3, arr2);
            Matrix res = mat + mat2;
            Matrix expected = new Matrix(3, 3, arr_exp);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert.AreEqual(res[i, j], expected[i, j]);
                }
            }
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void TestMinus1()
        {
            int[,] arr = new int[3, 3];
            Matrix mat = new Matrix(3, 3, arr);
            int[,] arr2 = new int[4, 5];
            Matrix mat2 = new Matrix(4, 5, arr2);
            Matrix res = mat - mat2;
        }
        [TestMethod]
        public void TestMinus2()
        {
            int[,] arr = new int[3, 3];
            int[,] arr2 = new int[3, 3];
            int[,] arr_exp = new int[3, 3];
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    arr[i, j] = 1;
                    arr2[i, j] = 1;
                    arr_exp[i, j] = 0;
                }
            }
            Matrix mat = new Matrix(3, 3, arr);
            Matrix mat2 = new Matrix(3, 3, arr2);
            Matrix res = mat - mat2;
            Matrix expected = new Matrix(3, 3, arr_exp);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert.AreEqual(res[i, j], expected[i, j]);
                }
            }
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void TestMult1()
        {
            int[,] arr = new int[3, 3];
            Matrix mat = new Matrix(3, 3, arr);
            int[,] arr2 = new int[4, 5];
            Matrix mat2 = new Matrix(4, 5, arr2);
            Matrix res = mat * mat2;
        }
        [TestMethod]
        public void TestMult2()
        {
            int[,] arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            int[,] arr2 = { { 1, 1, 1 }, { 2, 2, 2 }, { 3, 3, 3 } };
            int[,] arr_exp = { { 14, 14, 14 }, { 32, 32, 32 }, { 50, 50, 50 } };
            Matrix mat = new Matrix(3, 3, arr);
            Matrix mat2 = new Matrix(3, 3, arr2);
            Matrix res = mat * mat2;
            Matrix expected = new Matrix(3, 3, arr_exp);
            for (int i = 0; i < 3; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert.AreEqual(res[i, j], expected[i, j]);
                }
            }
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentException))]
        public void TestEq1()
        {
            int[,] arr = new int[3, 3];
            Matrix mat = new Matrix(3, 3, arr);
            int[,] arr2 = new int[4, 5];
            Matrix mat2 = new Matrix(4, 5, arr2);
            bool res = mat == mat2;
        }
        [TestMethod]
        public void TestEq2()
        {
            int[,] arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            int[,] arr2 = { { 1, 2, 3 }, { 4, 4, 6 }, { 7, 8, 9 } };
            Matrix mat = new Matrix(3, 3, arr);
            Matrix mat2 = new Matrix(3, 3, arr2);
            bool res = mat == mat2;
            bool expected = false;
            Assert.AreEqual (expected, res);
        }
        [TestMethod]
        public void TestEq3()
        {
            int[,] arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            int[,] arr2 = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            Matrix mat = new Matrix(3, 3, arr);
            Matrix mat2 = new Matrix(3, 3, arr2);
            bool res = mat == mat2;
            bool expected = true;
            Assert.AreEqual(expected, res);
        }
        [TestMethod]
        public void TestTrans()
        {
            /*
             * 1 2       1 3 5
             * 3 4  ->   2 4 6
             * 5 6
             */
            int[,] arr = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
            int[,] arr_exp = { { 1, 3, 5 }, { 2, 4, 6 }};
            Matrix mat = new Matrix(3, 2, arr);
            Matrix expected = new Matrix(2, 3, arr_exp);
            Matrix res = mat.Transpose();
            for (int i = 0; i < 2; i++)
            {
                for (int j = 0; j < 3; j++)
                {
                    Assert.AreEqual(res[i, j], expected[i, j]);
                }
            }
        }
        [TestMethod]
        public void TestMin()
        {
            int[,] arr = { { 1, 2 }, { 3, 4 }, { 5, 6 } };
            Matrix mat = new Matrix(3, 2, arr);
            int res = mat.Min();
            int expected = 1;
            Assert.AreEqual(expected, res);
        }
        [TestMethod]
        public void TestString()
        {
            int[,] arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            Matrix mat = new Matrix(3, 3, arr);
            string res = mat.ToString();
            string expected = "[[1, 2, 3], [4, 5, 6], [7, 8, 9]]";
            Assert.AreEqual(expected, res);
        }
        [TestMethod]
        [ExpectedException(typeof(ArgumentOutOfRangeException))]
        public void TestIndex1()
        {
            int[,] arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            Matrix mat = new Matrix(3, 3, arr);
            int el = mat[-1, 5];
        }
        [TestMethod]
        public void TestIndex2()
        {
            int[,] arr = { { 1, 2, 3 }, { 4, 5, 6 }, { 7, 8, 9 } };
            Matrix mat = new Matrix(3, 3, arr);
            int el = mat[1, 1];
            int expected = 5;
            Assert.AreEqual(expected, el);
        }
        [TestMethod]
        public void TestRows()
        {
            int[,] arr = new int[2, 3];
            Matrix mat = new Matrix(2, 3, arr);
            int rows = mat.Rows;
            int expected = 2;
            Assert.AreEqual(expected, rows);
        }
        [TestMethod]
        public void TestCols()
        {
            int[,] arr = new int[2, 3];
            Matrix mat = new Matrix(2, 3, arr);
            int cols = mat.Cols;
            int expected = 3;
            Assert.AreEqual(expected, cols);
        }
    }
}