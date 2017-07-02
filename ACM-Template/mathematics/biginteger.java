// hdu 1402
import java.math.BigInteger;
import java.io.*;
class Main {
    static BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
    static BufferedWriter out = new BufferedWriter(new OutputStreamWriter(System.out));
    public static void main(String []args) throws Exception{
        String temp;
        while((temp = in.readLine()) != null) {
            BigInteger a = new BigInteger(temp);
            BigInteger b = new BigInteger(in.readLine());
            out.write(a.multiply(b).toString());
            out.newLine();
        }
        out.flush();
    }
}