double m_gear_ratio = 30.0;
double m_ppr = 13.0;
double m_D = 0.065;
double m_v = 0.0;
double m_w = 0.0;
double m_v_input = 0.0;
double m_w_input = 0.0;
double v_r = 0;
double v_l = 0;
double target_r = 0;
double target_l = 0;
double m_required_v_r = 0;
double m_required_v_l = 0;
double target_rotation_r = 0;
double target_rotation_l = 0;
double out_rpm_r = 0;
double out_rpm_l = 0;
double m_base_long = 0.081;

void setup() {
Serial.begin(9600);
}

void loop() {
if(Serial.available()==4){
    int A = Serial.read()-48;
    int B = Serial.read()-48;
    int C = Serial.read()-48;
    int D = Serial.read()-48;

    m_v_input = B/10.0;
    m_w_input = D/10.0;
Serial.printf("m_v_input: %.2f ,m_w_input: %.2f\n",m_v_input,m_w_input);  
  }
    else{
    int serial_length = Serial.available();
    for(int i=0;i<serial_length;i++){
      int dummy_reader = Serial.read();
      Serial.print("dummy_reader:");
      Serial.println(dummy_reader);
    }
    }
    
  //v_r = rmp_r/m_ppr/m_gear_ratio*3.14159*m_D; 
  //v_l = rmp_l/m_ppr/m_gear_ratio*3.14159*m_D;

  target_r = m_v_input*m_gear_ratio/3.14159/m_D*4*60;
  target_l = m_v_input*m_gear_ratio/3.14159/m_D*4*60;

  m_required_v_r = m_base_long * m_w_input;
  m_required_v_l = -1.0*m_base_long * m_w_input;
  target_rotation_r = m_required_v_r*m_gear_ratio/3.14159/m_D*4*60;
  target_rotation_l = m_required_v_l*m_gear_ratio/3.14159/m_D*4*60;

  out_rpm_r=target_r + target_rotation_r;
  out_rpm_l=target_l + target_rotation_l;
  Serial.printf("out_rpm_r: %.2f ,out_rpm_l: %.2f\n",out_rpm_r,out_rpm_l);
  delay(1000);
  
}
