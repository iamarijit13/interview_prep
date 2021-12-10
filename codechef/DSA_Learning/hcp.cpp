#define _CRT_SECURE_NO_WARNINGS

#include <cstdio>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <complex>
#include <queue>

#ifdef ONLINE_JUDGE
#include <sys/resource.h>
#else
#pragma comment(linker, "/STACK:266777216")
#endif

using std::cin;
using std::cout;
using std::endl;
using std::lower_bound;
using std::make_pair;
using std::map;
using std::max;
using std::min;
using std::next_permutation;
using std::pair;
using std::queue;
using std::set;
using std::sort;
using std::string;
using std::swap;
using std::upper_bound;
using std::unique;
using std::vector;
//using namespace std;

#define assert(f) { if(!(f)) { fprintf(stderr,"Assertion failed: "); fprintf(stderr,#f); fprintf(stderr,"\n"); exit(1); } }

typedef long long LL;
typedef unsigned long long ULL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef pair<int,int> PII;
typedef vector<PII> VPII;
typedef vector<double> VD;
typedef pair<double,double> PDD;

const int inf=1000000000;
const LL INF=LL(inf)*inf;
const double eps=1e-9;
const double PI=2*acos(0.0);
#define bit(n) (1<<(n))
#define bit64(n) ((LL(1))<<(n))
#define pb push_back
#define sz size()
#define mp make_pair
#define cl clear()
#define all(a) (a).begin(),(a).end()
#define fill(ar,val) memset((ar),(val),sizeof (ar))
#define MIN(a,b) {if((a)>(b)) (a)=(b);}
#define MAX(a,b) {if((a)<(b)) (a)=(b);}
#define sqr(x) ((x)*(x))
#define X first
#define Y second

class Random {
  ULL val;
  ULL next() {
    return val=6364136223846793005LL*val+1442695040888963407LL;
  }
  int clz(ULL n) {
    int res = 64;
    for(;n;n/=2)
      res--;
    return res;
  }
public:
  Random() {}
  Random(ULL _val): val(_val) {}
  double operator()(){
    return (next()>>11)/(double)(1ll<<53);
  }
  LL operator()(LL n) {
    if((n&-n)==n) {
      return next()>>(1+clz(n));
    }
    LL bits, val;
    do {
      bits=next()>>33;
      val=bits%n;
    } while(bits-val+(n-1)<0);
    return val;
  }
  LL operator()(LL lo, LL hi) {
    if(lo==hi) return lo;
    return operator()(hi-lo+1)+lo;
  }
} rnd;

const int N = 15;
const int N4 = N*(N+1)*N*(N+1)/4+10;

void printRow4(int m,int row,FILE* out=stdout) {
  for(int j=0;j<m;j++)
    fprintf(out,"%d",(row>>(2*j))&3);
  fprintf(out,"\n");
}

void printMatrix4(const VI& a, int m) {
  for(int i=0;i<a.sz;i++)
    printRow4(m,a[i]);
}

void printMask2(int n,int m,int mask, FILE* out = stdout) {
  for(int i=0;i<n;i++) {
    for(int j=0;j<m;j++) {
      fprintf(out, "%d", mask & bit(i*m+j) ? 1 : 0);
    }
    fprintf(out, "\n");
  }
}

VI mask4ToMatrix(int n, int m, int mask) {
  VI a(n);
  for(int i=0;i<n;i++)
    a[i] = (mask>>(2*i*m)) & (bit(2*m)-1);
  return a;
}

void printMask4(int n,int m,int mask) {
  printMatrix4(mask4ToMatrix(n,m,mask),m);
}

int countSubMatr2(int n, int m, int mask) {
  static pair<int,PII> subs[N4];
  int len=0;
  for(int y1=0;y1<m;y1++) {
    for(int y2=y1;y2<m;y2++) {
      int dy = y2-y1+1;
      int patt = bit(dy)-1;
      for(int x1=0;x1<n;x1++) {
        int sub=0;
        for(int x2=x1;x2<n;x2++) {
          sub ^= ((mask>>(x2*m+y1)) & patt)<<((x2-x1)*(dy));
          subs[len++] = mp(sub,mp(x2-x1+1,dy));
        }
      }
    }
  }
  sort(subs,subs+len);
  len = unique(subs,subs+len)-subs;
  return len;
}

// n = a.size()
// a[0], ..., a[n-1] - is the matrix
// a[i] - is the 4-base representation
// WARNING!!! `a` will be zeroed in the end
int countSubMatr4(VI a, int m) {
  int n = a.size();
  static pair<LL,PII> subs[N4];
  int len=0;
  for(int y1=0;y1<m;y1++) {
    for(int y2=y1;y2<m;y2++) {
      int dy = y2-y1+1;
      int patt = bit(2*dy)-1;
      for(int x1=0;x1<n;x1++) {
        LL sub=0;
        for(int x2=x1;x2<n;x2++) {
          sub = 1000000007 * sub + (a[x2] & patt);
          subs[len++] = mp(sub, mp(x2-x1+1,dy));
        }
      }
    }
    for(int x=0;x<n;x++) a[x]/=4;
  }
  sort(subs,subs+len);
  len = unique(subs,subs+len)-subs;
  return len;
}

int calcMaxK(int n,int m) {
  int maxK = 0;
  for(int h=1;h<=n;h++) {
    for(int w=1;w<=m;w++) {
      int cnt = (n-h+1)*(m-w+1);
      if (h*w < 10) {
        MIN(cnt, bit(2*h*w));
      }
      maxK += cnt;
    }
  }
  return maxK;
}

int countSubMatr4(int n, int m, int mask) {
  return countSubMatr4(mask4ToMatrix(n,m,mask),m);
}

void research(int n,int m) {
  /*char name[111];
  sprintf(name,"stats_%dx%d.txt",n,m);
  freopen(name,"w",stdout);*/
  int minC = n*m;
  int maxC = calcMaxK(n,m);
  puts("==========================================================");
  printf("n=%d m=%d minC=%d maxC=%d\n",n,m,minC,maxC);
  fprintf(stderr,"n=%d m=%d minC=%d maxC=%d\n",n,m,minC,maxC);
  VPII stats[N4];
  for(int mask=0;mask<bit(n*m-1);mask++) {
    int cnt = countSubMatr2(n,m,mask);
    stats[cnt].pb(mp(2,mask));
  }
  if(n*m<=10) {
    for(int mask=0;mask<bit(2*n*m-2);mask++) {
      int cnt = countSubMatr4(n,m,mask);
      stats[cnt].pb(mp(4,mask));
    }
  }
  for(int c=minC;c<=maxC;c++) {
    printf("cnt=%d:",c);
    const VPII& a = stats[c];
    if(a.empty()) {
      puts(" NO SAMPLES!!!"); 
    } else {
      printf("\n");
      a[0].X==2 ? printMask2(n,m,a[0].Y) : printMask4(n,m,a[0].Y);
    }
  }
}

void research() {
  freopen("stats.txt","w",stdout);
  for(int m=1;m<=N;m++)
    for(int n=1;n<=m && n*m<=18;n++)
      research(n,m);
}
struct test {
  int n,m,k;
  test(){}
  test(int n_,int m_,int k_): n(n_), m(m_), k(k_) {}
  bool operator<(const test& t) const {
    return n < t.n || (n == t.n && (m < t.m || (m == t.m && k < t.k)));
  }
  bool operator==(const test& t) const {
    return n == t.n && m == t.m && k == t.k;
  }
};

typedef map<int,VI> MIV;
typedef map<int,VI>::iterator MIVI;
map<PII, MIV> db;

void processMatr(const VI& a, int m) {
  static pair<LL,PII> subs[N4];
  int len=0;
  int n = a.sz;
  VI b;
  for(int x2=0;x2<n;x2++) {
    b.pb(a[x2]);
    for(int y1=0;y1<m;y1++)
      for(int y2=y1;y2<m;y2++) {
        int dy = y2-y1+1;
        int patt = bit(2*dy)-1;
        LL sub=0;
        for(int x1=x2;x1>=0;x1--) {
          sub = 1000000007 * sub + ((a[x1]>>(2*y1)) & patt);
          subs[len++] = mp(sub, mp(x2-x1+1,dy));
        }
      }
    sort(subs,subs+len);
    len = unique(subs,subs+len)-subs;
    db[mp(b.sz,m)].insert(mp(len,b));
  }
}

void genDb(int m) {
  // random matrices
  for(int it=0;it<20;it++) {
    VI a(m);
    for(int i=0;i<m;i++) {
      for(int j=0;j<m;j++) {
        int x = rnd(4);
        a[i] ^= x<<(2*j);
      }
    }
    processMatr(a, m);
  }
  // matrices with random small corner
  for(int it=0;it<20;it++) {
    VI a(m);
    for(int i=0;i<2;i++) {
      for(int j=0;j<2;j++) {
        int x = rnd(4);
        a[i] ^= x<<(2*j);
      }
    }
    processMatr(a, m);
  }
  // random matrices with equal rows
  for(int it=0;it<30;it++) {
    int gen=0;
    for(int j=0;j<m;j++)
      gen ^= rnd(4)<<(2*j);
    processMatr(VI(m, gen), m);
  }
  // random matrices with equal cols
  for(int it=0;it<30;it++) {
    VI a(m);
    for(int i=0;i<m;i++) {
      int x = rnd(4);
      for(int j=0;j<m;j++)
        a[i] ^= x<<(2*j);
    }
    processMatr(a, m);
  }
  processMatr(VI(m), m);
  processMatr(VI(m,1), m);
  VI a(m);
  a[0]=1;
  processMatr(a, m);
  a[1]=1;
  processMatr(a, m);
}

void print(const VI& a, int m, bool swp) {
  int n = a.sz;
  if(swp) {
    for(int j=0;j<m;j++) {
      for(int i=0;i<n;i++)
        putchar("ACGT"[(a[i]>>(2*j))&3]);
      printf("\n");
    }
  } else {
    for(int i=0;i<n;i++) {
      for(int j=0;j<m;j++)
        putchar("ACGT"[(a[i]>>(2*j))&3]);
      printf("\n");
    }
  }
}

void genMax() {
  FILE* maxF = fopen("max.txt","w");
  for(int m=1;m<=N;m++) {
    for(int it=0;it<1000;it++) {
      if(it%50==0) fprintf(stderr,"m=%d it=%d\n",m,it);
      VI a(m);
      for(int i=0;i<m;i++) {
        for(int j=0;j<m;j++) {
          int x = rnd(4);
          a[i] ^= x<<(2*j);
        }
      }
      processMatr(a, m);
    }
    for(int n=1;n<=m;n++) {
      MIVI it = --db[mp(n,m)].end();
      fprintf(stderr,"n=%d m=%d max=%d my=%d\n",n,m,calcMaxK(n,m),it->X);
      fprintf(maxF,"{%d,%d,%d",n,m,it->X);
      for(int i=0;i < it->Y.sz;i++)
        fprintf(maxF,",%d",it->Y[i]);
      fprintf(maxF,"},\n");
    }
  }
  exit(0);
}

int maxS[150][30]={
{1,1,1,0},
{1,2,3,4},
{2,2,9,3,9},
{1,3,6,54},
{2,3,16,7,59},
{3,3,31,2,37,61},
{1,4,10,135},
{2,4,26,206,145},
{3,4,52,183,161,62},
{4,4,86,5,222,217,44},
{1,5,14,625},
{2,5,39,625,355},
{3,5,78,300,526,471},
{4,5,129,152,1013,449,590},
{5,5,193,223,75,805,121,99},
{1,6,19,1598},
{2,6,55,1598,2676},
{3,6,109,1598,2676,1478},
{4,6,180,879,3030,3146,1400},
{5,6,270,4071,3179,2445,2380,3122},
{6,6,379,1935,403,2880,3198,1114,678},
{1,7,25,4813},
{2,7,74,14794,7124},
{3,7,145,15878,13351,12634},
{4,7,241,7915,1651,2399,4152},
{5,7,360,12805,10997,4322,1590,7578},
{6,7,508,790,15347,7336,2142,14772,13972},
{7,7,679,9713,3083,4975,6614,15498,7187,13372},
{1,8,32,24243},
{2,8,96,39954,22778},
{3,8,186,45575,9909,50042},
{4,8,311,33034,11593,63291,43143},
{5,8,467,59871,23770,57638,53441,26861},
{6,8,655,59871,23770,57638,53441,26861,21641},
{7,8,878,64717,33709,32194,50256,18630,44007,55248},
{8,8,1136,64993,12064,44379,44265,45249,24676,56728,13550},
{1,9,40,10692},
{2,9,118,170039,21229},
{3,9,234,153142,126072,10319},
{4,9,389,259760,57874,111838,217828},
{5,9,584,245548,121631,39518,53284,211491},
{6,9,823,42197,221370,211214,225656,252527,159812},
{7,9,1104,156440,173904,124250,229839,223936,35257,142614},
{8,9,1430,6022,211466,190882,147167,149764,58823,199829,101735},
{9,9,1796,177377,49236,204675,25031,219485,190951,157247,68601,213614},
{1,10,49,244903},
{2,10,144,792505,991963},
{3,10,287,792505,991963,289427},
{4,10,476,405653,984971,236826,851661},
{5,10,718,766826,845982,259095,306060,11542},
{6,10,1013,201640,586853,778689,15221,679717,360964},
{7,10,1356,824305,1003731,773864,489985,611225,509318,35644},
{8,10,1757,824305,1003731,773864,489985,611225,509318,35644,117354},
{9,10,2205,77434,460935,999220,511147,481902,407771,892413,180289,120090},
{10,10,2709,871744,312038,737706,936096,140147,514175,519240,401765,15551,823609},
{1,11,59,1112856},
{2,11,175,1888634,1641176},
{3,11,345,1888634,1641176,2637460},
{4,11,575,3284354,3152314,1722317,2474962},
{5,11,866,2368078,2042661,423398,377315,842255},
{6,11,1219,4099855,2225567,1579012,4012836,2904749,2856050},
{7,11,1635,2972932,3188163,1360319,2239361,1568346,3103192,4130377},
{8,11,2115,1026219,230424,1343389,2069529,575930,3857102,2771981,2610901},
{9,11,2657,1991113,1715010,2987039,3950610,1881943,2885254,397292,2682105,1824782},
{10,11,3262,1991113,1715010,2987039,3950610,1881943,2885254,397292,2682105,1824782,2268616},
{11,11,3934,2137363,3854920,2092355,2780605,3378010,629207,258819,2440627,2480512,2206664,2181680},
{1,12,70,9167921},
{2,12,206,5475014,11804006},
{3,12,409,7088546,13908165,15891862},
{4,12,681,1697389,1070876,8730798,864096},
{5,12,1027,7974875,9518047,6426866,6609246,2301176},
{6,12,1447,6467538,11539677,12359589,16392349,15983071,7920562},
{7,12,1944,7910510,15033307,958983,4488855,4344952,15412717,11456255},
{8,12,2516,2885269,11311357,15310088,10295160,13141575,16176077,16575565,15620623},
{9,12,3159,11345370,3545601,6723525,13814886,12923369,11251778,13107149,14933126,853498},
{10,12,3876,15308771,6257958,2723544,15106133,7289611,8041167,14706206,14952205,9755821,1750726},
{11,12,4673,15308771,6257958,2723544,15106133,7289611,8041167,14706206,14952205,9755821,1750726,9531521},
{12,12,5544,15308771,6257958,2723544,15106133,7289611,8041167,14706206,14952205,9755821,1750726,9531521,16093838},
{1,13,82,59150556},
{2,13,242,21396490,34434707},
{3,13,478,13111133,7234698,62821661},
{4,13,799,13111133,7234698,62821661,24043280},
{5,13,1203,13111133,7234698,62821661,24043280,3174438},
{6,13,1698,27425763,55413888,39308877,54599585,42644495,39667440},
{7,13,2275,20025029,55803993,49839231,7225977,4053591,64770740,54505112},
{8,13,2944,13993946,12694982,60899201,11159974,63503130,32324048,927120,57644190},
{9,13,3697,36271271,16732592,5723913,21749156,57525273,66483209,37616854,61741592,65016351},
{10,13,4539,5202314,34272783,23544965,60863853,6213326,163178,39065894,45381835,53636787,12576873},
{11,13,5470,34315178,62913184,1557283,48455327,63906302,7765291,57410383,57774690,64205379,23611897,52139295},
{12,13,6493,34315178,62913184,1557283,48455327,63906302,7765291,57410383,57774690,64205379,23611897,52139295,1379911},
{13,13,7599,34315178,62913184,1557283,48455327,63906302,7765291,57410383,57774690,64205379,23611897,52139295,1379911,36630989},
{1,14,95,151465613},
{2,14,278,7790841,36269043},
{3,14,554,155327385,3898762,147222635},
{4,14,925,152824648,20543252,163527912,106473955},
{5,14,1398,189798187,240891957,149321718,195177572,71732465},
{6,14,1968,189798187,240891957,149321718,195177572,71732465,77219796},
{7,14,2638,111074471,46978964,123976457,222436903,219367806,245013491,208095223},
{8,14,3411,51136922,99543254,245809783,43779650,267670744,122867694,159680438,247088375},
{9,14,4284,121779945,41618782,65189854,229513017,48666306,19604358,39911213,85256128,207023514},
{10,14,5257,121779945,41618782,65189854,229513017,48666306,19604358,39911213,85256128,207023514,230159694},
{11,14,6333,96033537,175717584,29695745,80260202,196363785,229664225,203729908,179657790,47827216,80896910,146160352},
{12,14,7508,77295965,190236089,27052661,202151363,266396405,173037774,69451660,104082748,110193534,239069993,51404392,76948789},
{13,14,8797,196910892,44339310,227570130,99786411,207233939,146040880,240951525,202131998,197945620,139741290,217701709,203458750,87952319},
{14,14,10184,213710183,172823153,243069700,77572334,250581643,246185369,27597449,1488587,216710316,26615973,69500609,50544064,223590276,30925712},
{1,15,109,252372500},
{2,15,318,160844606,399013901},
{3,15,633,336072555,758488312,77834384},
{4,15,1060,533366420,878439299,702857555,930026041},
{5,15,1600,947833379,616186016,385817357,109335691,261775549},
{6,15,2251,947833379,616186016,385817357,109335691,261775549,420368264},
{7,15,3027,495501113,736267389,883783654,287201296,606493809,100752330,675147111},
{8,15,3910,495501113,736267389,883783654,287201296,606493809,100752330,675147111,431070397},
{9,15,4913,495501113,736267389,883783654,287201296,606493809,100752330,675147111,431070397,279097677},
{10,15,6029,495501113,736267389,883783654,287201296,606493809,100752330,675147111,431070397,279097677,685998696},
{11,15,7263,495501113,736267389,883783654,287201296,606493809,100752330,675147111,431070397,279097677,685998696,936830057},
{12,15,8612,495501113,736267389,883783654,287201296,606493809,100752330,675147111,431070397,279097677,685998696,936830057,187771542},
{13,15,10083,727354262,380054378,928775226,255315315,375468909,772714093,233472140,202447104,863237838,665129583,167648709,112211596,1008633158},
{14,15,11670,619822339,496266872,537694826,949043663,44433816,506269940,427757388,88794143,921219972,881836444,669509254,86960759,192107443,829618954},
{15,15,13379,779181318,853269287,936374976,466365276,822355529,306208017,844042553,613219729,1034028348,617035269,720434907,384229788,1000963057,891989193,683375782}
};

int main()
{
  //genMax();
  clock_t start = clock();
#ifndef ONLINE_JUDGE
  freopen("in.txt","r",stdin);
  FILE* stats = fopen("stats.txt","w");
#else
  struct rlimit rl;
  rl.rlim_cur = 1024 * 1024 * 1024;
  setrlimit(RLIMIT_STACK, &rl);
#endif
  //countSubMatr4(1,3,6);
  //research();
  for(int i=0,n;n=maxS[i][0];i++)
    db[mp(n,maxS[i][1])].insert(mp(maxS[i][2],VI(maxS[i]+3,maxS[i]+3+n)));
  for(int m=1;m<=N;m++) {
    if(m==1) {
      db[mp(1,1)][1]=VI(1);
    } else {
      genDb(m);
    }
#ifndef ONLINE_JUDGE
    for(int n=1;n<=m;n++) {
      MIV& miv = db[mp(n,m)];
      fprintf(stats,"n=%d m=%d [%d,%d]: %d: %s\n",
        n,m,n*m,calcMaxK(n,m),miv.sz,miv.sz?"":"NO SAMPLES!!!!!!");
      for(MIVI it = miv.begin();it!=miv.end();++it)
        fprintf(stats,"%d ",it->X);
      fprintf(stats,"\n");
    }
#endif
  }
  int T;
  scanf("%d",&T);
  for(int t=0;t<T;t++) {
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    bool swp=false;
    if(n>m) {
      swap(n,m);
      swp=true;
    }
    MIV& miv = db[mp(n,m)];
    int bestK = -inf;
    VI bestA;
    for(MIVI it = miv.begin();it!=miv.end();++it) {
      if(abs(bestK - k) > abs(it->X - k)) {
        bestK = it->X;
        bestA = it->Y;
      }
    }
#ifndef ONLINE_JUDGE
    fprintf(stderr,"t=%d n=%d m=%d [%d,%d]: k=%d myk=%d sc=%lf\n",
      t,n,m,n*m,calcMaxK(n,m),k,bestK,fabs(k-bestK+0.)/k);
#endif
    assert(bestA.sz == n);
    print(bestA, m, swp);
  }
  fprintf(stderr, "time=%.3lfsec\n", double(clock() - start) / CLOCKS_PER_SEC);
  return 0;
}
