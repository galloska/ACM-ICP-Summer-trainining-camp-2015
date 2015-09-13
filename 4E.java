import java.io.*;
import java.math.*;
 
public class Main {
 
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new FileReader("ideal.in"));
        PrintStream bw = new PrintStream(new FileOutputStream("ideal.out"));
        String s, ps = null;
        String[] sarr;
        int p = 0, t = 0, v = 0, o = 0, e = 0, u = 0;
        int sa, psa = -1;
        String pr = "0";
        boolean[] sp = null;
        int[] i = null;
        int[] iq = null;
        int[] ir = null;
        boolean lineFound = false;
        int k, j;
        while ((s = br.readLine()) != null) {
            s = s.trim();
            if (s.replaceAll("-", "").equals("")) {
                if (ps != null) {
                    lineFound = true;
                    sarr = ps.split("\\s+");
                    if (sarr.length > 4 && sarr[0].equals("Team") &&
                        sarr[sarr.length - 3].equals("=") &&
                        sarr[sarr.length - 2].equals("Time") &&
                        sarr[sarr.length - 1].equals("R")) {
                        p = sarr.length - 4;
                        sp = new boolean[p];
                        i = new int[p];
                        iq = new int[p];
                        ir = new int[p];
                    }
                    pr = "0";
                    v = 0;
                    o = 0;
                    e = 0;
                    t = 0;
                    psa = -1;
                }
            } else if (lineFound) {
                t++;
                sarr = s.split("\\s+");
                if (sarr.length < (4 + p)) {
                    lineFound = false;
                } else {
                    sa = 0;
                    if (!pr.equals(sarr[sarr.length - 1])) {
                        for (k = 0; k < p; k++) {
                            iq[k] += ir[k];
                            ir[k] = 0;
                        }
                        pr = sarr[sarr.length - 1];
                    }
                    for (k = sarr.length - 3 - p, j = 0; k < sarr.length - 3; k++, j++) {
                        if (sarr[k].charAt(0) == '+') {
                            sp[j] = true;
                            sa++;
                            i[j] += iq[j];
                            iq[j] = 0;
                        } else {
                            ir[j]++;
                        }
                    }
                    if (sa == 0) {
                        v++;
                    } else if (sa == p) {
                        o++;
                    }
                    if (psa != -1 && psa != sa) {
                        e += psa - sa - 1;
                    }
                    psa = sa;
                }
            }
            ps = s;
        }
        for (k = 0; k < p; k++) {
            if (!sp[k]) {
                u++;
            }
        }
        double fv = (double)v / (double)t;
        double fo = (double)o / (double)t;
        double fe = (double)e / (double)p;
        double fu = (double)u / (double)p;
        double fi = 0;
        bw.printf("Vainness = %.3f\n", fv);
        bw.printf("Oversimplification = %.3f\n", fo);
        bw.printf("Evenness = %.3f\n", fe);
        bw.printf("Unsolvability = %.3f\n", fu);
        for (k = 0; k < p; k++) {
            bw.printf("Instability %d = %.3f\n", k + 1, (double)i[k] / (double)t);
            fi += (double)i[k] / (double)t;
        }
        fi /= (double)p;
        bw.printf("Negidealness = %.3f\n", 1.03 * fv + 3.141 * fo + 2.171 * fe + 1.414 * fu + fi);
    }
 
}
