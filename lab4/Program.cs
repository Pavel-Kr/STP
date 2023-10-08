public class Matrix
{
    int[,] elements;
    public int Rows { get; }
    public int Cols { get; }
    public Matrix(int rows, int cols, int[,] mat)
    {
        if (mat == null) 
            throw new ArgumentNullException();
        if (rows <= 0 || cols <= 0) 
            throw new ArgumentOutOfRangeException();
        Rows = rows; Cols = cols;
        elements = mat;
    }
    public static Matrix operator +(Matrix a, Matrix b)
    {
        if(a.Rows != b.Rows || a.Cols != b.Cols) 
            throw new ArgumentException("Both matrices must have equal amount of rows and columns");
        Matrix res = new Matrix(a.Rows, a.Cols, new int[a.Rows, a.Cols]);
        for(int i = 0;
            i < a.Rows;
            i++)
        {
            for(int j = 0;
                j < a.Cols;
                j++)
            {
                res.elements[i, j] = a[i, j] + b[i, j];
            }
        }
        return res;
    }
    public static Matrix operator -(Matrix a, Matrix b)
    {
        if (a.Rows != b.Rows || a.Cols != b.Cols)
            throw new ArgumentException("Both matrices must have equal amount of rows and columns");
        Matrix res = new Matrix(a.Rows, a.Cols, new int[a.Rows, a.Cols]);
        for (int i = 0; i < a.Rows; i++)
        {
            for (int j = 0; j < a.Cols; j++)
            {
                res.elements[i, j] = a[i, j] - b[i, j];
            }
        }
        return res;
    }
    public static Matrix operator *(Matrix a, Matrix b)
    {
        if (a.Cols != b.Rows)
            throw new ArgumentException("Number of columns in left matrix != number of rows in right matrix");
        Matrix res = new Matrix(a.Rows, b.Cols, new int[a.Rows, b.Cols]);
        for (int i = 0; i < a.Rows; i++)
        {
            for (int j = 0; j < b.Cols; j++)
            {
                res.elements[i, j] = 0;
                for(int k = 0; k < a.Cols; k++)
                {
                    res.elements[i, j] += a[i, k] * b[k, j];
                }
            }
        }
        return res;
    }
    public static bool operator ==(Matrix a, Matrix b)
    {
        if (a.Rows != b.Rows || a.Cols != b.Cols)
            throw new ArgumentException("Both matrices must have equal amount of rows and columns");
        for (int i = 0;
            i < a.Rows;
            i++)
        {
            for (int j = 0;
                j < a.Cols;
                j++)
            {
                if (a[i, j] != b[i, j])
                    return false;
            }
        }
        return true;
    }
    public static bool operator !=(Matrix a, Matrix b)
    {
        if (a.Rows != b.Rows || a.Cols != b.Cols)
            throw new ArgumentException("Both matrices must have equal amount of rows and columns");
        for (int i = 0; i < a.Rows; i++)
        {
            for (int j = 0; j < a.Cols; j++)
            {
                if (a[i, j] == b[i, j]) return false;
            }
        }
        return true;
    }
    public Matrix Transpose()
    {
        Matrix res = new Matrix(Cols, Rows, new int[Cols, Rows]);
        for(int i = 0; i < Rows; i++)
        {
            for(int j = 0; j < Cols; j++)
            {
                res.elements[j, i] = elements[i, j];
            }
        }
        return res;
    }
    public int Min()
    {
        int min = Int32.MaxValue;
        for(int i = 0;
            i < Rows;
            i++)
        {
            for(int j = 0;
                j < Cols;
                j++)
            {
                if (elements[i, j] < min) 
                    min = elements[i, j];
            }
        }
        return min;
    }
    public override String ToString()
    {
        string res = "[";
        for(int i = 0;
            i < Rows;
            i++)
        {
            res += "[";
            for(int j = 0;
                j < Cols;
                j++)
            {
                res += elements[i, j].ToString();
                if(j + 1 < Cols)
                    res += ", ";
            }
            res += "]";
            if (i + 1 < Rows)
                res += ", ";
        }
        res += "]";
        return res;
    }
    public int this[int i, int j]
    {
        get
        {
            if ((i < 0) || (j < 0) || i >= Rows || j >= Cols)
                throw new ArgumentOutOfRangeException();
            return elements[i, j];
        }
    }
}

class Program
{
    public static void Main()
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
                arr_exp[i, j] = 2;
            }
        }
        Matrix mat = new Matrix(3, 3, arr);
        Matrix mat2 = new Matrix(3, 3, arr2);
        Matrix res = mat + mat2;
        Console.WriteLine(res.ToString());
    }
}