#include <windows.h>
#include <iostream>
#include<GL/gl.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

float cloudX = 0.0f; // Initial position of the cloud
float cloudSpeed = 0.00009f; // Speed of cloud movement
float satelliteAngle = 0.0f; // Initial angle of the satellite

void Ground(){

    glPushMatrix();

    glTranslatef(0.0f, 0.0f, 0.0f);

    glScalef(1.0f, 1.0f, 0.0f);


    glBegin(GL_POLYGON);
        glColor3ub( 156, 56, 8  );

        glVertex2f(0.0f, 0.0f);//A
        glVertex2f(0.0f, 5.0f);//T
        glVertex2f(20.0f,5.133f);//K1
        glVertex2f(20.0f,0.0f);//M
        glVertex2f(0.0f, 0.0f);//A
    glEnd();

    glPopMatrix();
}
void Road() {
    //Road
    glColor3ub(50, 50, 50); // Asphalt-like road color
    glBegin(GL_POLYGON);
    glVertex2f(0.0f, 0.0f); // Point A
    glVertex2f(0.0f, 1.64f); // Point I4
    glVertex2f(20.0f, 1.64f); // Point J4
    glVertex2f(20.0f, 0.0f); // Point M
    glEnd();

    // Divider 1 (K4, L4)
    glColor3ub(255, 255, 255); // White divider
    glBegin(GL_QUADS);
    glVertex2f(0.9866012525882f,0.73345215050f); //S4
    glVertex2f(0.9893873618254f,0.8126270172124f); //K4
    glVertex2f(1.9946079902207f,0.8126270172124f); //L4
    glVertex2f(1.9910285859428f,0.72850423260f); //V4
    glEnd();

    // Divider 2
    glBegin(GL_QUADS);
    glVertex2f(5.0102698754067f,0.812627017212f); //  M4
    glVertex2f(6.0009220888978f,0.8126270172124f); // N4
    glVertex2f(6.0037900014626f,0.7384000684052f); //Z4
    glVertex2f(5.0092585039047f,0.7334521505069f); //W4
    glEnd();

    // Divider 3
    glBegin(GL_QUADS);
    glVertex2f(9.0020155591795f,0.7980586023082f); //  O4
    glVertex2f(10.0f,0.8f); // P4
    glVertex2f(10.0027801123285f,0.72551026f); //B5
    glVertex2f(9.0008048552594f,0.725510269393f); //A5
    glEnd();

     // Divider 4
    glBegin(GL_QUADS);
    glVertex2f(13.0f,0.8f); //  R4
    glVertex2f(13.9989818713475f,0.7980586023082f); // Q4
    glVertex2f(14.0010157844272f,0.7351756255f); //D5
    glVertex2f(13.0022623127506f,0.735175625571f); //C5
    glEnd();

      // Divider 5
    glBegin(GL_QUADS);
    glVertex2f(17.0f,0.8f); //  U4
    glVertex2f(18.0f,0.8f); // T4
    glVertex2f(18.002099328201f,0.7378029496602f); //F5
    glVertex2f(17.0011543215519,0.7378029496602f); //E5
    glEnd();
}
void House() {

    // Top Floor
    glPushMatrix();

    glBegin(GL_POLYGON);
    glColor3ub(61, 168, 221 ); // Light blue
    glVertex2f(7.5714f,5.938f);  //B7
    glVertex2f(7.6130323197172f,6.10979404758f);  // C7
    glVertex2f(7.6959453882368f,6.285374663277f); // D7
    glVertex2f(7.8081218927046f,6.465832518290f); // E7
    glVertex2f(7.9202983971724f,6.617026937356f);  //F7
    glVertex2f(8.0471066196142f,6.753589638447f);  //G7
    glVertex2f(8.1836693207054f,6.870643382239f);  // H7
    glVertex2f(8.3153547824719f,6.9925743653568f); // I7
    glVertex2f(8.437285765589f,7.0901191518505f); // J7
    glVertex2f(8.5689712273555f,7.1535232630714f);  //K7
    glVertex2f(8.7201656464208f,7.212050134967f);  //L7
    glVertex2f(8.8518511081873f,7.260822528214f);  // M7
    glVertex2f(8.9981682879278f,7.2949632034873f); // N7
    glVertex2f(9.1591171856424f,7.3242266394354f); // O7
    glVertex2f(9.305434365383f,7.343735596734f);  //P7
    glVertex2f(9.4322425878248f,7.3534900753835f);  //Q7
    glVertex2f(9.568805288916f,7.3681217933576f);  // R7
    glVertex2f(9.6907362720331f,7.372999032682f); // S7
    glVertex2f(9.8126672551503f,7.368121793357f); // T7
    glVertex2f(9.9053348023193f,7.36812179335f);  //U7
    glVertex2f(9.9980023494883f,7.3583673147082f);  //V7
    glVertex2f(10.095547135982f,7.3388583574f);  // W7
    glVertex2f(10.1833374438264f,7.3193494001f); // Z7
    glVertex2f(10.2711277516707f,7.2949632034f); // A8
    glVertex2f(10.3686725381644f,7.2608225282145f);  //B8
    glVertex2f(10.4613400853334f,7.226681852f);  //C8
    glVertex2f(10.5637621111518f,7.168154981045f);  // D8
    glVertex2f(10.6613068976455f,7.11938258779f); // E8
    glVertex2f(10.7637289234639f,7.05597847f); // F8
    glVertex2f(10.8612737099576f,6.98281988670f);  //G8
    glVertex2f(10.9734502144254f,6.87552062156f);  //H8
    glVertex2f(11.0905039582178f,6.7682213564213f);  // I8
    glVertex2f(11.2026804626856f,6.6462903733041f); // J8
    glVertex2f(11.3002252491793f,6.5292366295117f); // K8
    glVertex2f(11.4f,6.4f);  //L8
    glVertex2f(11.490437582842f,6.260988466654f);  //M8
    glVertex2f(11.5392099760889f,6.1341802442122f);  // N8
    glVertex2f(11.5733506513617f,5.9781085858223f); // O8
    glVertex2f(10.8383809954668f,6.0876462676612f); // R2
    glVertex2f(9.8259344572106f,6.130501147587f);  //S2
     glVertex2f(8.6152840992958f,6.0876462676612f); // Q2
    glVertex2f(7.5714f,5.938f);  //B7


    glEnd();
    glPopMatrix();


    //Border of Top floor
    glPushMatrix();
        glBegin(GL_POLYGON);
        glColor3ub(100, 100, 100); // Dark grey for the roof
        glVertex2f(8.9981682879278f,7.2949632034873f);  // N7
        glVertex2f(9.0810813564475f,7.4461576225525f); //P8
        glVertex2f(9.2078895788893f,7.514438973098f);  // Q8
        glVertex2f(9.3444522799805f,7.563211366345f);  // R8
        glVertex2f(9.6322094001369f,7.572965844994f);  // S8
        glVertex2f(9.7882810585269f,7.5437024090462f);  // T8
        glVertex2f(9.9394754775921f,7.509561733773f);  // U8
        glVertex2f(9.9980023494883f,7.358367314708f); //V7
        glVertex2f(9.9053348023193f,7.3681217933576f);  // U7
        glVertex2f(9.8126672551503f,7.3681217933576f);  // T7
        glVertex2f(9.6907362720331f,7.3729990326823f);  // S7
        glVertex2f(9.568805288916f,7.3681217933576f); //R7
        glVertex2f(9.4322425878248f,7.3534900753835f);  // Q7
        glVertex2f(9.305434365383f,7.3437355967341f);  // P7
        glVertex2f(9.1591171856424f,7.3242266394354f);  // O7
        glVertex2f(8.9981682879278f,7.2949632034873f); // N7
    glEnd();
    glPopMatrix();



    // Roof
    glPushMatrix();
        glBegin(GL_POLYGON);
    glColor3ub(100, 100, 100); // Dark grey for the roof
    glVertex2f(9.3444522799805f,7.56321136634f);  // R8
    glVertex2f(9.3444522799805f,7.733914742709f); //V8
    glVertex2f(9.6273321608122f,7.748546460683f);  // W8
    glVertex2f(9.6322094001369f,7.5729658449f);  // S8
    glVertex2f(9.3444522799805f,7.563211366345f);  // R8
    glEnd();
    glPopMatrix();

   // 2nd floor top
    glPushMatrix();
        glBegin(GL_POLYGON);
    glColor3ub(80, 50, 20); //
    glVertex2f(7.1339899075961f,5.7488082669788f);  //H2
    glVertex2f(7.4484220541606f,5.9203167105594f);  //G2
    glVertex2f(7.571f,5.938f);  //B7
    glVertex2f(8.6152840992958f,6.08764626766f);  //Q2
    glVertex2f(9.8259344572106f,6.1305011475873f);  //S2
    glVertex2f(10.8383809954668f,6.087646267f);  //R2
    glVertex2f(11.5733506513617f,5.97810858582f);  //O8
    glVertex2f(11.6503789218853f,5.9560476363f);  //L2
    glVertex2f(12.0648576605384f,5.8131239333215f);  //M2
    glVertex2f(11.5860632555425f,5.627323119442f);  //N2
    glVertex2f(11.4115650144796f,5.819803268122f);  //Z2
    glVertex2f(10.8276672754853f,5.9001561679841f);  //V2
    glVertex2f(9.8098638772383f,5.91622674795f);  //U2
    glVertex2f(8.6045703793143f,5.8680150080394f);  //T2
    glVertex2f(8.0474569402738f,5.81980326f);  //W2
    glVertex2f(7.5055915353541f,5.60588456399f);  //I2
    glVertex2f(7.1339899075961f,5.7488082669788f);  //H2

    glEnd();
    glPopMatrix();

    //2nd floor
    glPushMatrix();
        glBegin(GL_POLYGON);
    glColor3ub(100, 100, 100); //
    glVertex2f(7.5055915353541f,5.60588456399f);  //I2
    glVertex2f(8.0474569402738f,5.8198032681225f);  //W2
    glVertex2f(8.6045703793143f,5.86801500803f);  //T2
    glVertex2f(9.8098638772383f,5.9162267479564f);  //U2
    glVertex2f(10.8276672754853f,5.9001561679f);  //V2
    glVertex2f(11.4115650144796f,5.81980326f);  //Z2
    glVertex2f(11.5860632555425f,5.6273231194f);  //N2
    glVertex2f(11.378823886216f,5.270013861f);  //O2
    glVertex2f(11.3859700713652f,5.01275119661f);  //P2
    glVertex2f(10.7044594956975f,5.010917409515f);  //I3
    glVertex2f(9.8527187571645f,5.0377017094696f);  //H3
    glVertex2f(8.9313388387514f,5.026987989f);  //D3
    glVertex2f(7.7485618304266f,4.9913126411645f);  //K2
    glVertex2f(7.7485618304266f,5.241429121386f);  //J2
    glVertex2f(7.5055915353541f,5.60588456399f);  //T2
    glEnd();
    glPopMatrix();

   //1st floor top
    glPushMatrix();
        glBegin(GL_POLYGON);
    glColor3ub(80, 50, 20); //
    glVertex2f(6.9385869221837f,4.8984233497094f);  //A3
    glVertex2f(7.3671357214456f,4.97341938958f);  //C3
    glVertex2f(7.7485618304266f,4.991312641164f);  //K2
    glVertex2f(8.9313388387514f,5.0269879894f);  //D3
    glVertex2f(9.8527187571645f,5.03770170946f);  //H3
    glVertex2f(10.7044594956975f,5.0109174095f);  //I3
    glVertex2f(11.3859700713652f,5.0127511966f);  //P2
    glVertex2f(11.8668981136953f,4.9734193f);  //E3
    glVertex2f(12.1454548332156f,4.925207649663f);  //F3
    glVertex2f(12.1454548332156f,4.8180704f);  //G3
    glVertex2f(11.8883255536584f,4.86628218f);  //P3
    glVertex2f(11.3847807145257f,4.9037802097f);  //O3
    glVertex2f(10.6991026357067f,4.909137069f);  //N3
    glVertex2f(9.8473618971737f,4.9252076496633f);  //M3
    glVertex2f(8.9527662787145f,4.9144939296f);  //L3
    glVertex2f(7.7314022008182f,4.8716390497556f);  //K3
    glVertex2f(7.3832063014179f,4.85556846978f);  //J3
    glVertex2f(6.9493006421652f,4.76985870993f);  //B3
    glVertex2f(6.9385869221837f,4.8984233497094f);  //A3


    glVertex2f(7.3832063014179f,4.85556846978f);  //J3
    glVertex2f(7.7314022008182f,4.8716390497556f);  //K3
    glVertex2f(8.9527662787145f,4.91449392968f);  //L3
    glVertex2f(9.8473618971737f,4.92520764966f);  //M3
    glVertex2f(10.6991026357067f,4.90913706969f);  //N3
    glVertex2f(11.3847807145257f,4.9037802097002f);  //O3
    glVertex2f(11.8883255536584f,4.8662821f);  //P3
    glVertex2f(11.8776118336769f,4.7430744099f);  //W3
    glVertex2f(11.3204983946364f,4.7645018f);  //V3
    glVertex2f(10.6991026357067f,4.8019998698755);  //U3
    glVertex2f(9.8420050371829f,4.81271358);  //T3
    glVertex2f(8.942052558733f,4.7912861498f);  //S3
    glVertex2f(7.8760374205691f,4.753788129f);  //R3
    glVertex2f(7.696f,4.744);  //Z3
    glVertex2f(7.3884859307112f,4.7247697951f);  //Q3
    glVertex2f(7.3832063014179f,4.85556846978f);  //J3


    glEnd();
    glPopMatrix();


    //1st floor
    glPushMatrix();
        glBegin(GL_POLYGON);
    glColor3ub(100, 100, 100); //
    glVertex2f(7.8492531206152f,3.96097285132f);  //A4
    glVertex2f(7.8760374205691f,4.753788129958f);  //R3
    glVertex2f(8.942052558733f,4.791286149894f);  //S3
    glVertex2f(9.8420050371829f,4.812713589f);  //T3
    glVertex2f(10.6991026357067f,4.8019998698f);  //U3
    glVertex2f(11.3204983946364f,4.7645018499f);  //V3
    glVertex2f(11.3204983946364f,3.95561599133f);  //B4
    glVertex2f(7.8492531206152f,3.96097285f);  //A4
    glEnd();
    glPopMatrix();

    //Ground top
    glPushMatrix();
        glBegin(GL_POLYGON);
    glColor3ub(80, 50, 20); //
    glVertex2f(6.6740031510782f,3.89002432f);  //E4
    glVertex2f(6.6171753227373f,4.01454145123f);  //D4
    glVertex2f(7.8492531206152f,3.96097285132f);  //A4
    glVertex2f(11.3204983946364f,3.9556159f);  //B4
    glVertex2f(12.5f,4.0f);  //C4
    glVertex2f(12.3959980572244f,3.84078168f);  //F4
    glVertex2f(11.3372812716638f,3.78661478f);  //H5
    glVertex2f(7.8459780113732f,3.811236101925f);  //G5
    glVertex2f(7.565f,3.83f);  //Q55
    glVertex2f(7.025f,3.830f);  //K5
    glVertex2f(6.6740031510782f,3.89002432f);  //E4
    glEnd();
    glPopMatrix();


    //Ground floor
    glPushMatrix();
        glBegin(GL_POLYGON);
    glColor3ub(100, 100, 100); //
    glVertex2f(7.565f,3.830f);  //Q5
    glVertex2f(7.2768312165444f,3.3952651603f);  //R5
    glVertex2f(7.5f,3.0f);  //S5
    glVertex2f(11.639797234823781f,3.0217200044631f);  //D9
    glVertex2f(11.933023133268492f,3.37244117f);  //K9
    glVertex2f(11.645546762244267f,3.81515478f);  //H5
    glVertex2f(7.8459780113732f,3.8112361019259f);  //G5
    glVertex2f(7.565f,3.830f);  //Q5
    glEnd();
    glPopMatrix();


// Top floor glass
    glPushMatrix();
        glBegin(GL_LINE);
    glColor3ub(0, 1, 1); // Black
    glVertex2f(7.6959453882368f,6.28537466327f);  // D7
    glVertex2f(8.3055823726851f,6.43483330f);  // L9
    glVertex2f(8.618f,6.473);  // R9
    glVertex2f(8.9171458680116,6.5102315459362f);  // M9
    glVertex2f(9.235f,6.505f);  // T9
    glVertex2f(9.5f,6.5f);  // N9
    glVertex2f(10.0f,6.5f);  // O9
    glVertex2f(10.4251106510085f,6.51023154f);  // P9
    glVertex2f(10.894255250163f,6.45996605316f);  // Q9
    glVertex2f(11.4f,6.4f);  // L8
    glEnd();
    glPopMatrix();

    //Window1
    glPushMatrix();
        glBegin(GL_POLYGON);
    glColor3ub(61, 168, 221); // Dark grey for the roof
    glVertex2f(8.159135437694601f,5.53193637f);  // N15
    glVertex2f(8.4183888724402f,5.5306320818f); //Q16
    glVertex2f(8.4183888724402f,5.26787527f);  //P16
    glVertex2f(8.1591354376946f,5.26928277f);  // O15
    glVertex2f(8.159135437694601f,5.53193637f);  // N15
    glEnd();
    glPopMatrix();



     // Window2
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(61, 168, 221); // Dark grey for the roof
    glVertex2f(9.4269749420939f,5.532844884f);  // R8
    glVertex2f(9.6828411233286f,5.532844884f); //V8
    glVertex2f(9.6828411233286f,5.2606468f);  // W8
    glVertex2f(9.4188090001397f,5.26336880015f);  // S8
    glVertex2f(9.4269749420939f,5.532844884f);  // R8
    glEnd();
    glPopMatrix();

    // Window3
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3ub(61, 168, 221); // Dark grey for the roof
    glVertex2f(10.4269749420939f,5.532844884f);  // R8
    glVertex2f(10.6828411233286f,5.532844884f); //V8
    glVertex2f(10.6828411233286f,5.2606468f);  // W8
    glVertex2f(10.4188090001397f,5.26336880015f);  // S8
    glVertex2f(10.4269749420939f,5.532844884f);  // R8
    glEnd();
    glPopMatrix();


}
void BackgroundHouse(){

    glBegin(GL_POLYGON);
	glColor3ub( 61, 168, 221 );

	glVertex2f(12.5896150780002f,5.0457939702f);//F16
	glVertex2f(12.3785624400961f,5.064980573695f);//J16
	glVertex2f(12.4041445780239f,5.25045107f);//L16
	glVertex2f(12.4680999228433f,5.4295260f);//M16
    glVertex2f(12.5832195435182f,5.6149965391419f);//N16
    glVertex2f(12.7750855779765f,5.8004670391f);//O16
    glVertex2f(13.0564890951819f,5.9155866597931f);//R16
    glVertex2f(13.2995194054957f,5.921982194f);//S16
	glVertex2f(13.593713991665f,5.8452357804918f);//T16
	glVertex2f(13.8303487674968f,5.69813848740f);//U16
	glVertex2f(14.0158192674731f,5.42313050468f);//V16
    glVertex2f(14.0925656812564f,5.1033537805f);//K16
    glVertex2f(13.9262817847259f,5.077771642f);//I16
    glVertex2f(12.5896150780002f,5.0457939702f);//F16

    glEnd();
    glPopMatrix();


    //Border
    glBegin(GL_POLYGON);
	glColor3ub(94, 59, 43 );

	glVertex2f(12.6663614917835f,4.9754430f);//G16
	glVertex2f(12.3785624400961f,5.06498057369f);//J16
	glVertex2f(12.5896150780002f,5.04579397024f);//F16
	glVertex2f(13.9262817847259f,5.07777164265f);//I16
    glVertex2f(14.0925656812564f,5.1033537805866f);//K16
    glVertex2f(13.8239532330148f,5.0010252288755f);//H16
    glVertex2f(12.8646230607236f,4.9882341599117f);//E2
    glVertex2f(12.6663614917835f,4.9754430f);//G16



    glEnd();
    glPopMatrix();

    //Base
    glBegin(GL_POLYGON);
	glColor3ub( 142, 131, 121 );

	glVertex2f(12.7381590863876f,4.9809792424888f);//E2
	glVertex2f(12.7342239263335f,4.4158105181986f);//I13
	glVertex2f(13.7456244431516f,4.419776794735f);//C16
	glVertex2f(13.744709893883f,4.9968304363076f);//B16
    glVertex2f(12.7381590863876f,4.9809792424888f);//E2

    glEnd();
    glPopMatrix();


    glBegin(GL_POLYGON);
	glColor3ub( 94, 59, 43 );

	glVertex2f(12.7342239263335f,4.4158105181986f);//I13
	glVertex2f(12.5968950253686f,4.30623464236f);//Z16
	glVertex2f(13.8582853440501f,4.3122127955345f);//A17
	glVertex2f(13.7456244431516f,4.4197767947f);//C16
    glVertex2f(12.7342239263335f,4.4158105181986f);//I13

    glEnd();
    glPopMatrix();


   //Door
    glBegin(GL_POLYGON);
	glColor3ub( 88, 44, 24);

	glVertex2f(13.147879880724f,4.7691827445778f);//W16
	glVertex2f(13.1427504095973f,4.4594395601006f);//D16
	glVertex2f(13.3886595548629f,4.4515070070275f);//E16
	glVertex2f(13.3937894089871f,4.76999871313f);//B17
    glVertex2f(13.147879880724f,4.7691827445778f);//W16

    glEnd();
    glPopMatrix();

}
void hill1(){

glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


   glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8  );

	glVertex2f(0.2559729526672f,4.6585950413223f);//E
	glVertex2f(1.0f,5.0f);//F
	glVertex2f(1.5181818181818f,5.547832526039f);//T
	glVertex2f(1.7165328579851f,6.1668107799193f);//S
	glVertex2f(2.1527121163506f,7.5769166817699f);//G
    glVertex2f(3.2011269722014f, 5.770540f);//H
    glVertex2f(3.9073628850488f, 4.8539368895f);//I
    glVertex2f(2.7353117956424f,4.5984898f);//O1
    glVertex2f(1.9839969947408f, 4.703673929376f);//N1
    glVertex2f(1.2477084898573f, 4.3430428249f);//M1
    glVertex2f(0.2559729526672f,4.6585950413223f);//E

glEnd();
glPopMatrix();

    glBegin(GL_POLYGON);
	glColor3ub(213, 106, 6  );

	glVertex2f(2.9432440584945f,6.2012426836f);//S6
	glVertex2f(3.183f,4.696f);//T6
	glVertex2f(3.2011269722014f,5.77054094f);//H
	glVertex2f(2.9432440584945f,6.2012426836f);//S6


glEnd();
glPopMatrix();

glBegin(GL_POLYGON);
	glColor3ub(213, 106, 6  );

	glVertex2f(2.1527121163506f,7.5769166817f);//G
	glVertex2f(1.852f,6.615f);//V6
	glVertex2f(2.1093724708101f,6.240638191f);//H19
	glVertex2f(2.1527121163506f,7.5769166817f);//G


glEnd();
glPopMatrix();




glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


   glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8);

	glVertex2f(1.623365890308f, 2.79533433f);//S
	glVertex2f(2.7202854996243f, 3.1709917f);//R
	glVertex2f(3.3513899323817f, 3.99743801f);//U
    glVertex2f(4.0f, 6.0f);//K
    glVertex2f(5.42501878287f, 2.825386927122f);//Q
    glVertex2f(4.5835462058603f, 2.46475582f);//Q1
    glVertex2f(3.3513899323817f, 2.4497295266717f);//P1
    glVertex2f(1.623365890308f, 2.79533433f);//S


glEnd();
glPopMatrix();

}
void hill3(){

glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


   glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8  );

	glVertex2f(4.0033453754188f,4.6539538707183f);//L
	glVertex2f(5.2447032306536f,7.6338016528f);//N
	glVertex2f(6.6722013523666f, 4.59848985f);//P
	glVertex2f(5.905860255447f, 4.59848985725f);//V
	glVertex2f(5.2296769346355f,4.373095f);//S1

	glVertex2f(4.0033453754188f,4.6539538707183f);//L


glEnd();
glPopMatrix();


glBegin(GL_POLYGON);
	glColor3ub( 213, 106, 6  );

	glVertex2f(5.3988973954548f,7.2255258937351f);//I19
	glVertex2f(5.2807108712161f,6.28003369f);//J19
	glVertex2f(5.535f,7.016f);//K19
	glVertex2f(5.3988973954548f,7.2255258937351f);//I19



glEnd();
glPopMatrix();



glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


   glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8  );

	glVertex2f(4.1071192030301f,4.6193625948479f);//L
	glVertex2f(5.4400450788881f,5.66535687f);//O
	glVertex2f(6.6722013523666f, 4.59848985f);//V
	glVertex2f(5.905860255447f, 4.59848985725f);//S1
    glVertex2f(6.6722013523666f, 4.59848985f);//R1
	glVertex2f(4.1071192030301f,4.6193625948479f);//L

glEnd();
glPopMatrix();

}
void hill5(){

glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


   glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8  );

	glVertex2f(13.6293764087152f,4.508332081142f);//W
	glVertex2f(14.0350864012021f,4.82388429f);//Z
	glVertex2f(14.4107438016529f,5.4850413f);//A1
	glVertex2f(14.8765589782119f,5.7254620586026f);//B1
    glVertex2f(15.3273478587528f,6.176250f);//C1
    glVertex2f(15.9584522915101f,7.618775f);//D1
    glVertex2f(17.1154770848986f,5.42493613f);//I1
    glVertex2f(16.6346356123212f,4.643568f);//A2
    glVertex2f(15.6128474830951f,4.793831f);//W1
    glVertex2f(14.9817430503378f,4.5534109f);//V1
    glVertex2f(14.2154019534182f,4.252885048835f);//U1
    glVertex2f(13.6293764087152f,4.508332081142f);//W

glEnd();
glPopMatrix();

}
void hill6(){

glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


   glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8  );

	glVertex2f(15.0117956423741f,2.5549135f);//E1
	glVertex2f(17.1906085649887f,6.010961f);//F1
	glVertex2f(17.5512396694213f,7.22809166f);//G1
	glVertex2f(19.3844477836213f,3.36633f);//H1
    glVertex2f(18.3626596543948f,2.79533433f);//D2
    glVertex2f(16.514425244177f,2.299466566f);//C2
    glVertex2f(15.0117956423741f,2.5549135f);//E1


glEnd();
glPopMatrix();

}
void hill7(){

glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


   glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8  );

	glVertex2f(18.36f,5.52f);//L1
	glVertex2f(19.0839218632605f,7.663854f);//J1
	glVertex2f(20.0f,5.0f);//K1
	glVertex2f(18.6181066867014f,4.538384f);//B2
    glVertex2f(18.36f,5.52f);//L1


glEnd();
glPopMatrix();

}
void BackgroundHill1(){

glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


    glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8 );

	glVertex2f(0.0f,5.0f);//T1
	glVertex2f(0.0f,5.558f);//O
	glVertex2f(0.7210475454616f,6.7772756206f);//K
	glVertex2f(1.5181818181818f,5.54783252603);//T
    glVertex2f(1.0f,5.0f);//F
    glVertex2f(0.0f,5.0f);//T1


glEnd();
glPopMatrix();

}
void BackgroundHill2(){

glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


    glBegin(GL_POLYGON);
	glColor3ub(181, 72, 8  );

	glVertex2f(3.803f,4.989f);//U5
	glVertex2f(3.2011269722014f,5.7705409f);//H
	glVertex2f(3.7967433678669f,6.651969494f);//P1
	glVertex2f(4.492f,5.827);//Q1
    glVertex2f(4.143f,4.99f);//V5
    glVertex2f(3.803f,4.989f);//U5


glEnd();
glPopMatrix();

}
void BackgroundHill3(){

glPushMatrix();
    /*Transalation*/
    glTranslatef(0.0f, 0.0f, 0.0f);
    /*Scaling*/
	glScalef(1.0f, 1.0f, 0.0f);


    glBegin(GL_POLYGON);
	glColor3ub( 181, 72, 8 );

	glVertex2f(6.011f,6.005f);//Q
	glVertex2f(6.8382647922455f,7.4379806491f);//R
	glVertex2f(7.6959453882368f,6.2853746632774f);//D7
	glVertex2f(7.6130323197172f,6.109794047588f);//C7
    glVertex2f(7.571f,5.938f);//B7
    glVertex2f(7.4484220541606f,5.92031671f);//G2
	glVertex2f(7.1339899075961f,5.748808266978f);//H2
	glVertex2f(7.5055915353541f,5.6058845f);//I2
	glVertex2f(7.7485618304266f,5.241429121386f);//J2
    glVertex2f(7.7485618304266f,4.9913126411f);//K2
    glVertex2f(7.3671357214456f,4.973419389f);//C3
	glVertex2f(6.9385869221837f,4.898423349f);//A3
	glVertex2f(6.9493006421652f,4.769858709f);//B3
	glVertex2f(6.531f,4.898);//R1
    glVertex2f(6.011f,6.005f);//Q



glEnd();
glPopMatrix();

}
void drawModernBuilding() {
    // Base structure
    glColor3ub(180, 180, 180); // Light grey for the building
    glBegin(GL_POLYGON);
    glVertex2f(0.2, 0.1);
    glVertex2f(0.2, 0.7);
    glVertex2f(0.6, 0.9);
    glVertex2f(1.0, 0.7);
    glVertex2f(1.0, 0.1);
    glEnd();

    // Windows - Lower Level
    glColor3ub(255, 255, 255); // White windows
    glBegin(GL_POLYGON);
    glVertex2f(0.25, 0.15);
    glVertex2f(0.25, 0.3);
    glVertex2f(0.45, 0.3);
    glVertex2f(0.45, 0.15);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.55, 0.15);
    glVertex2f(0.55, 0.3);
    glVertex2f(0.75, 0.3);
    glVertex2f(0.75, 0.15);
    glEnd();

    // Upper Level Windows
    glBegin(GL_POLYGON);
    glVertex2f(0.35, 0.35);
    glVertex2f(0.35, 0.5);
    glVertex2f(0.55, 0.5);
    glVertex2f(0.55, 0.35);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex2f(0.65, 0.35);
    glVertex2f(0.65, 0.5);
    glVertex2f(0.85, 0.5);
    glVertex2f(0.85, 0.35);
    glEnd();

    // Roof
    glColor3ub(100, 100, 100); // Dark grey
    glBegin(GL_POLYGON);
    glVertex2f(0.15, 0.7);
    glVertex2f(0.6, 1.0);
    glVertex2f(1.05, 0.7);
    glEnd();
}




void Cloud() {
    glPushMatrix();
    glTranslatef(cloudX, 0.0f, 0.0f);

    glBegin(GL_POLYGON);
    glColor3ub(221, 223, 223);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.1416 / 180;
        glVertex2f(0.4609 + cos(angle) * 0.4, 7.8497 + sin(angle) * 0.25);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(221, 223, 223);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.1416 / 180;
        glVertex2f(0.7391 + cos(angle) * 0.4, 8.2349 + sin(angle) * 0.25);
    }
    glEnd();

    glBegin(GL_POLYGON);
    glColor3ub(221, 223, 223);
    for (int i = 0; i < 360; i++) {
        float angle = i * 3.1416 / 180;
        glVertex2f(0.9459 + cos(angle) * 0.4, 7.8568 + sin(angle) * 0.25);
    }
    glEnd();

    glPopMatrix();
}

void car3(){

glPushMatrix();

	/*Transalation*/

    glTranslatef(cloudX*1.5, -1.5f, 0.0f);

    /*Scaling*/

	glScalef(0.6f, 0.6f, 0.0f);

        /*Rotation*/

    //glRotatef(0,1.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);

	glColor3ub(32, 34, 220);

	glVertex2f(13.61,5.78);//S2

	glVertex2f(15.17,5.78);//T2

	glVertex2f(15.79,5.31);//V2

	glVertex2f(12.98,5.32);//U2

	glEnd();

	glBegin(GL_POLYGON);

	glColor3ub(220, 34, 32);

	glVertex2f(12.98,5.32);//U2

	glVertex2f(12.18,5.32);//W2

	glVertex2f(12.18,4.74);//Z2

	glVertex2f(16.58,4.74);//A3

	glVertex2f(16.58,5.31);//B3

	glVertex2f(15.79,5.31);//V2

	glVertex2f(12.98,5.32);//U2

	glEnd();

	//WINDOW

	 glBegin(GL_POLYGON);

	glColor3ub(0,0,0);

	glVertex2f(13.61,5.67);//G3

	glVertex2f(14.19,5.67);//H3

	glVertex2f(14.2,5.4);//J3

	glVertex2f(13.25,5.4);//I3

	glEnd();

	 glBegin(GL_POLYGON);

	glColor3ub(0,0,0);

	glVertex2f(14.48,5.68);//K3

	glVertex2f(15.09,5.68);//L3

	glVertex2f(15.46,5.41);//M3

	glVertex2f(14.47,5.41);//N3

	glEnd();

	//WHEEL

	glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)

        {

            glColor3ub(   0,0,0   );

            float pi=3.1416;

            float A=(i*2*pi)/200;

            float r=0.4;

            float x = r * cos(A);

            float y = r * sin(A);

            glVertex2f(x+15.8,y+4.47);

        }

        glEnd();

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)

        {

            glColor3ub(   0,0,0   );

            float pi=3.1416;

            float A=(i*2*pi)/200;

            float r=0.4;

            float x = r * cos(A);

            float y = r * sin(A);

            glVertex2f(x+13.20,y+4.47);

        }

        glEnd();

glPopMatrix();

}


void car4(){

glPushMatrix();

	/*Transalation*/

    glTranslatef(cloudX*1.5+5, -2.2f, 0.0f);

    /*Scaling*/

	glScalef(0.6f, 0.6f, 0.0f);

        /*Rotation*/

    //glRotatef(0,1.0f, 0.0f, 1.0f);

    glBegin(GL_POLYGON);

	glColor3ub(232, 34, 220);

	glVertex2f(13.61,5.78);//S2

	glVertex2f(15.17,5.78);//T2

	glVertex2f(15.79,5.31);//V2

	glVertex2f(12.98,5.32);//U2

	glEnd();

	glBegin(GL_POLYGON);

	glColor3ub(120, 134, 32);

	glVertex2f(12.98,5.32);//U2

	glVertex2f(12.18,5.32);//W2

	glVertex2f(12.18,4.74);//Z2

	glVertex2f(16.58,4.74);//A3

	glVertex2f(16.58,5.31);//B3

	glVertex2f(15.79,5.31);//V2

	glVertex2f(12.98,5.32);//U2

	glEnd();

	//WINDOW

	 glBegin(GL_POLYGON);

	glColor3ub(0,0,0);

	glVertex2f(13.61,5.67);//G3

	glVertex2f(14.19,5.67);//H3

	glVertex2f(14.2,5.4);//J3

	glVertex2f(13.25,5.4);//I3

	glEnd();

	 glBegin(GL_POLYGON);

	glColor3ub(0,0,0);

	glVertex2f(14.48,5.68);//K3

	glVertex2f(15.09,5.68);//L3

	glVertex2f(15.46,5.41);//M3

	glVertex2f(14.47,5.41);//N3

	glEnd();

	//WHEEL

	glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)

        {

            glColor3ub(   0,0,0   );

            float pi=3.1416;

            float A=(i*2*pi)/200;

            float r=0.4;

            float x = r * cos(A);

            float y = r * sin(A);

            glVertex2f(x+15.8,y+4.47);

        }

        glEnd();

    glBegin(GL_POLYGON);

	for(int i=0;i<200;i++)

        {

            glColor3ub(   0,0,0   );

            float pi=3.1416;

            float A=(i*2*pi)/200;

            float r=0.4;

            float x = r * cos(A);

            float y = r * sin(A);

            glVertex2f(x+13.20,y+4.47);

        }

        glEnd();

glPopMatrix();

}


void updateCloud(int value) {
    cloudX += cloudSpeed;
    satelliteAngle += 0.01f;
    if (cloudX > 25.5f) { // Reset position when it moves far right
        cloudX = -30.5f;
    }
    glutPostRedisplay();
    glutTimerFunc(2000, updateCloud, 0); // Approx 60 FPS update
}

void Cloud2(){

    glPushMatrix();
    glTranslatef(-cloudX, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(   221, 223, 223     );

 for(int i=0;i<360;i++)
 {

     float angle =i*3.1416/180;
     glVertex2f(6.9062861618817+cos(angle)*0.30,9.4547881870901+sin(angle)*0.25);
 }

glEnd();

glBegin(GL_POLYGON);
    glColor3ub(   221, 223, 223     );

 for(int i=0;i<360;i++)
 {

     float angle =i*3.1416/180;
     glVertex2f(7.1478335253811+cos(angle)*0.30,9.812944622+sin(angle)*0.25);
 }

glEnd();


glBegin(GL_POLYGON);
    glColor3ub(   221, 223, 223     );

 for(int i=0;i<360;i++)
 {

     float angle =i*3.1416/180;
     glVertex2f(7.4060393277427+cos(angle)*0.30,9.52975116196+sin(angle)*0.25);
 }

glEnd();


glPopMatrix();

}
void Cloud3(){

    glPushMatrix();
    glTranslatef(-cloudX, 0.0f, 0.0f);
    glBegin(GL_POLYGON);
    glColor3ub(   221, 223, 223     );

    for(int i=0;i<360;i++)
    {

     float angle =i*3.1416/180;
     glVertex2f(14.4567819219632+cos(angle)*0.35,8.2758484869466+sin(angle)*0.23);
    }

     glEnd();


    glBegin(GL_POLYGON);
    glColor3ub(   221, 223, 223     );

    for(int i=0;i<360;i++)
    {

     float angle =i*3.1416/180;
     glVertex2f(14.7966291783094+cos(angle)*0.33,8.58017951339+sin(angle)*0.23);
    }

     glEnd();


    glBegin(GL_POLYGON);
    glColor3ub( 221, 223, 223   );

    for(int i=0;i<360;i++)
    {

     float angle =i*3.1416/180;
     glVertex2f(15.0970820005163+cos(angle)*0.35,8.333619922+sin(angle)*0.23);
    }

     glEnd();


    glPopMatrix();

}
void marssky() {
    glBegin(GL_QUADS);
    // Bottom part of the sky
    glColor3ub(246, 225, 217); // Lighter shade
    glVertex2f(0.0f, 0.0f);
    glVertex2f(20.0f, 0.0f);

    // Top part of the sky
    glColor3ub(230, 164, 118); // Darker shade
    glVertex2f(20.0f, 10.0f);
    glVertex2f(0.0f, 10.0f);
    glEnd();
}


void Satellite(){

glPushMatrix();

    glTranslatef(12.0f, 9.0f, 0.0f); // Move to orbit center
    glRotatef(satelliteAngle, 1.0f, 0.0f, 0.0f); // Rotate around Z-axis
    glTranslatef(-12.0f, -9.0f, 0.0f); // Move back


	glScalef(1.0f, 1.0f, 0.0f);

    //Base
    glBegin(GL_POLYGON);
	glColor3ub( 255, 255, 255 );

	glVertex2f(11.6779064893067f,9.1273291504f);//B10
	glVertex2f(11.9069955530587f,9.3269939307f);//C10
	glVertex2f(11.9637423853643f,9.339604337f);//F10
	glVertex2f(12.0099805450207f,9.32909566f);//G10
    glVertex2f(12.043608297498f,9.3038748509705f);//H10
    glVertex2f(12.0604221737367f,9.27024709f);//I10
	glVertex2f(12.0646256427964f,9.22400893f);//J10
	glVertex2f(12.0478117665577f,9.175669044f);//E10
	glVertex2f(11.801908826567f,8.96969906072f);//D10
    glVertex2f(11.7598741359703f,8.959190f);//O10
    glVertex2f(11.7199411799034f,8.9675973261f);//N10
	glVertex2f(11.6842116928962f,8.99281814f);//K10
	glVertex2f(11.6547874094785f,9.03695456f);//M10
	glVertex2f(11.6589908785382f,9.089497928f);//L10
    glVertex2f(11.6779064893067f,9.1273291504f);//B10

    glEnd();



    //Plate Upper
    glBegin(GL_POLYGON);
	glColor3ub(72, 152, 184);

	glVertex2f(11.4698347708531f,9.068480f);//P10
	glVertex2f(11.5518024175166f,9.0789892562782f);//Q10
	glVertex2f(11.6043457807625f,9.0621753f);//R10
	glVertex2f(11.6547874094785f,9.036954565f);//M10
    glVertex2f(11.6842116928962f,8.992818140f);//K10
    glVertex2f(11.6968221000752f,8.93396957f);//S10
	glVertex2f(11.7010255691349f,8.87301927235f);//T10
	glVertex2f(11.6863134274261f,8.80786550f);//U10
	glVertex2f(11.6400752677697f,8.753220404153f);//V10
    glVertex2f(11.623261391531f,8.82888284722f);//B11
    glVertex2f(11.5959388426432f,8.9108504938f);//A11
	glVertex2f(11.5623110901658f,8.97600426f);//Z10
	glVertex2f(11.5202763995691f,9.02854762756f);//W10
	glVertex2f(11.4698347708531f,9.068480f);//P10


    glEnd();




    //Right

    glBegin(GL_POLYGON);
	glColor3ub(13, 91, 178);

	glVertex2f(11.9133007566482,8.946579980f);//D12
	glVertex2f(12.1571019621091f,9.137837823f);//E12
	glVertex2f(12.6993494708065f,8.66915102f);//G12
	glVertex2f(12.4555482653457,8.469486242f);//F12
    glVertex2f(11.9133007566482,8.946579980f);//D12

    glEnd();


     //Inside
    glBegin(GL_POLYGON);
	glColor3ub(26, 58, 94);

	glVertex2f(11.993166668782f,8.952885184f);//H12
	glVertex2f(12.1465932894599f,9.081090990808f);//I12
	glVertex2f(12.2411713433025f,8.994919875084f);//J12
	glVertex2f(12.0856429880947f,8.8688158032947f);//K12
    glVertex2f(11.993166668782f,8.952885184f);//H12

    glEnd();




    glBegin(GL_POLYGON);
	glColor3ub(26, 58, 94);

	glVertex2f(12.1213724751019f,8.83728978f);//L12
	glVertex2f(12.2790025648395f,8.961292122f);//O12
	glVertex2f(12.3672754150926f,8.885629679f);//N12
	glVertex2f(12.2075435908251f,8.7616273422f);//M12
    glVertex2f(12.1213724751019f,8.8372897f);//L12

    glEnd();



    glBegin(GL_POLYGON);
	glColor3ub(26, 58, 94);

	glVertex2f(12.2453748123622f,8.72169438f);//P12
	glVertex2f(12.4030049020998f,8.8520019270f);//Q12
	glVertex2f(12.4996846904722f,8.76793254f);//R12
	glVertex2f(12.3420546007346f,8.64182847f);//S12
    glVertex2f(12.2453748123622f,8.72169438f);//P12

    glEnd();



    glBegin(GL_POLYGON);
	glColor3ub(26, 58, 94);

	glVertex2f(12.3672754150926f,8.61450592f);//T12
	glVertex2f(12.5270072393601f,8.732203058855f);//U12
	glVertex2f(12.617381824143f,8.6607440f);//V12
	glVertex2f(12.4618534689352f,8.528334809461f);//W12
    glVertex2f(12.3672754150926f,8.6145059251f);//T12

    glEnd();




    //Stick

    glBegin(GL_POLYGON);
	glColor3ub(0,0,0);

	glVertex2f(11.9477234407062f,9.082481980f);//Z12
	glVertex2f(11.9793127662799f,9.109590381f);//B13
	glVertex2f(12.0427356252545f,9.0476089510f);//C13
	glVertex2f(12.006f,9.02f);//A13
    glVertex2f(11.9477234407062f,9.082481980f);//Z12

    glEnd();







    //Right

    glBegin(GL_POLYGON);
	glColor3ub(13, 91, 178);

	glVertex2f(11.5938371081133f,9.238721080f);//K11
	glVertex2f(11.0536913339457f,9.71161134f);//H11
	glVertex2f(11.2974925394066f,9.90286919f);//I11
	glVertex2f(11.8355365790443f,9.4320806f);//J11
    glVertex2f(11.5938371081133f,9.238721080f);//K11

    glEnd();


     //Inside
    glBegin(GL_POLYGON);
	glColor3ub(26, 58, 94);

	glVertex2f(11.1335572460795f,9.7242217f);//L11
	glVertex2f(11.2844695547646f,9.8418719868828f);//M11
	glVertex2f(11.3662252806824f,9.775771612f);//N11
	glVertex2f(11.2134231582132f,9.650661048f);//O11
    glVertex2f(11.1335572460795f,9.7242217f);//L11

    glEnd();




    glBegin(GL_POLYGON);
	glColor3ub(26, 58, 94);

	glVertex2f(11.2596613178696f,9.6128298268f);//P11
	glVertex2f(11.4097123689365f,9.73576349f);//Q11
	glVertex2f(11.4966865454447f,9.660965699f);//R11
	glVertex2f(11.3470909618505f,9.527025f);//S11
    glVertex2f(11.2596613178696f,9.6128298268f);//P11

    glEnd();



    glBegin(GL_POLYGON);
	glColor3ub(26, 58, 94);

	glVertex2f(11.394172327779f,9.488827489f);//T11
	glVertex2f(11.5436526007592f,9.612260160f);//U11
	glVertex2f(11.6341057443277f,9.539201852f);//V11
	glVertex2f(11.4740732595526f,9.4174380f);//W11
    glVertex2f(11.394172327779f,9.488827489f);//T11

    glEnd();



    glBegin(GL_POLYGON);
	glColor3ub(26, 58, 94);

	glVertex2f(11.5181746650393f,9.37323209045f);//Z11
	glVertex2f(11.6706348984612f,9.504412182f);//A12
	glVertex2f(11.7558695914393f,9.43309335f);//B12
	glVertex2f(11.6f,9.3f);//C12
    glVertex2f(11.5181746650393f,9.37323209045f);//Z11

    glEnd();



    //Stick

    glBegin(GL_POLYGON);
	glColor3ub(0,0,0);

	glVertex2f(11.685f,9.3113f);//D13
	glVertex2f(11.721f,9.341f);//F13
	glVertex2f(11.8203058313146f,9.2456778f);//G13
	glVertex2f(11.7860952687946f,9.2174169162768);//E13
    glVertex2f(11.685f,9.3113f);//D13

    glEnd();
    glPopMatrix();

glutSwapBuffers();
}

void Planet(){

   //Round
    glBegin(GL_POLYGON);
    glColor3ub(   221, 223, 223     );

 for(int i=0;i<360;i++)
 {

     float angle =i*3.1416/180;
     glVertex2f(4.4612244430616+cos(angle)*0.7,8.662502404405+sin(angle)*0.7);
 }

glEnd();


//Ring




}
void Sun(){

    glBegin(GL_POLYGON);
    glColor3ub(  235, 222, 57  );

 for(int i=0;i<360;i++)
 {

     float angle =i*3.1416/180;
     glVertex2f(18.2540937316345+cos(angle)*0.541,9.24434289+sin(angle)*0.41);
 }

glEnd();

  //surround


    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(17.0869744582365f,9.37166654f);//G17
	glVertex2f(17.0802686419987f,9.274432208f);//H17
	glVertex2f(17.5664403192343f,9.2844909326f);//F17
	glVertex2f(17.5700246327573f,9.3832944f);//E17
    glVertex2f(17.0869744582365f,9.37166654f);//G17
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(17.598960713055f,9.056449042717f);//I17
	glVertex2f(17.3547460631314f,8.94987882341f);//K17
	glVertex2f(17.3972302956427f,8.8676737897f);//L17
	glVertex2f(17.6452291574156f,8.9731658428685f);//J17
    glVertex2f(17.598960713055f,9.056449042717f);//I17
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(17.7860023315805f,8.79442598f);//O17
	glVertex2f(17.8511922326252f,8.72422147364f);//P17
	glVertex2f(17.5001696885387f,8.36316971400f);//R17
	glVertex2f(17.4319080197163f,8.4434484283473f);//Q17
    glVertex2f(17.7860023315805f,8.79442598f);//O17
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(18.091893405713f,8.613900102643f);//S17
	glVertex2f(18.170838685352f,8.6104212390814f);//T17
	glVertex2f(18.182156345621f,8.3581551062371f);//U17
	glVertex2f(18.0944623753077f,8.3501762132f);//V17
    glVertex2f(18.091893405713f,8.613900102643f);//S17
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(18.4321721196625f,8.626776575282f);//N17
	glVertex2f(18.5157954849313f,8.6685882f);//W17
	glVertex2f(18.7698818640173f,8.305148247325f);//Z17
	glVertex2f(18.6798259321894f,8.250471431f);//A18
    glVertex2f(18.4321721196625f,8.626776575282f);//N17
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(18.757016730899f,8.83583498845f);//B18
	glVertex2f(18.8084772633721f,8.9130257871f);//C18
	glVertex2f(19.0304008096625f,8.784374455981f);//D18
	glVertex2f(18.9757239939098f,8.713616223f);//E18
    glVertex2f(18.757016730899f,8.83583498845f);//B18
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(18.904203122605f,9.1679707633f);//G18
	glVertex2f(18.9295878986015f,9.2638688060f);//F18
	glVertex2f(19.4069815721856f,9.170760794f);//I18
	glVertex2f(19.3634256002406f,9.0642906f);//H18
    glVertex2f(18.904203122605f,9.1679707633f);//G18
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(18.8590746319444f,9.5487424033f);//K18
	glVertex2f(18.8117166222696f,9.6305182766013f);//J18
	glVertex2f(19.1214479783235f,9.7611861924f);//L18
	glVertex2f(19.1354866372404f,9.67284575f);//M18
    glVertex2f(18.8590746319444f,9.5487424033f);//K18
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(18.5310225808458f,9.848298136f);//O18
	glVertex2f(18.4535897418323f,9.9015332131484f);//N18
	glVertex2f(18.7294442308178f,10.30321606f);//P18
	glVertex2f(18.8213957271463f,10.2548205411f);//Q18
    glVertex2f(18.5310225808458f,9.848298136f);//O18
    glEnd();


    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(17.9696344979981f,9.87249589851f);//R18
	glVertex2f(18.0857837565183f,9.92573097534f);//S18
	glVertex2f(17.9067203162997f,10.288697408215f);//U18
	glVertex2f(17.7808919529028f,10.2403018838f);//T18
    glVertex2f(17.9696344979981f,9.87249589851f);//R18
    glEnd();

    glBegin(GL_POLYGON);
	glColor3ub( 235, 222, 57 );

	glVertex2f(17.698619561451f,9.6547160387f);//W18
	glVertex2f(17.7518546382727f,9.7321488778f);//V18
	glVertex2f(17.529235226109f,9.86281679364f);//Z18
	glVertex2f(17.4760001492872f,9.7805444021899f);//A19
    glVertex2f(17.698619561451f,9.6547160387f);//W18
    glEnd();


}


void display() {

	 glClear(GL_COLOR_BUFFER_BIT);
	 glMatrixMode(GL_MODELVIEW);

	 marssky();
     Ground();
	 hill1();

	 hill3();

	 hill5();
	 hill6();
     hill7();
     House();
     drawModernBuilding();
	 Road();
	 Satellite();
	 Planet();
     BackgroundHouse();
     Sun();






	 BackgroundHill1();
	 BackgroundHill2();
	 BackgroundHill3();

     Cloud();
     Cloud2();
     Cloud3();
    updateCloud(0);
    car3();
    car4();


	glFlush();  // Render now
}

void handleKeyboard(unsigned char key, int x, int y) {
    switch (key) {
        case '+':
            cloudSpeed += 0.0002f; // Increase speed
            break;
        case '-':
            cloudSpeed -= 0.0003f; // Decrease speed
            if (cloudSpeed < 0.0001f) cloudSpeed = 0.0001f; // Prevent negative speed
            break;
        default:
            break;
    }
    glutPostRedisplay();
}

void initGL() {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
	glutInit(&argc, argv);

               // Initialize GLUT

    glutInitWindowSize(1400,750);
	glutInitWindowPosition(50,20);

    glutCreateWindow("Project Mars"); // Create a window with the given title
	glutDisplayFunc(display); // Register display callback handler for window re-paint
	initGL();
	gluOrtho2D(0,20,0,10);// axis define
    glutKeyboardFunc(handleKeyboard); // Register keyboard function

	glutMainLoop();           // Enter the event-processing loop
	return 0;
}
