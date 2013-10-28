/*
	Comp 2659 Assignment: Missile Command
	Donovan Paget & Ryan Wright
*/




void play_music()
{	
	/* OCTAVE 3 */
	struct sound_effect note_c =
	{
	{0,1},
	{0x57,0x03},
	2
	};
	struct sound_effect note_c_sharp =
	{
	{0,1},
	{0x94,0x01},
	2
	};
	struct sound_effect note_d =
	{
	{0,1},
	{0xFA,0x02},
	2
	};
	struct sound_effect note_d_sharp =
	{
	{0,1},
	{0x68,0x01},
	2
	};
	struct sound_effect note_e =
	{
	{0,1},
	{0xA7,0x02},
	2
	};
	struct sound_effect note_f =
	{
	{0,1},
	{0x81,0x02},
	2
	};
	struct sound_effect note_f_sharp =
	{
	{0,1},
	{0x2E,0x01},
	2
	};
	struct sound_effect note_g =
	{
	{0,1},
	{0x3B,0x02},
	2
	};
	struct sound_effect note_g_sharp =
	{
	{0,1},
	{0x0D,0x01},
	2
	};
	struct sound_effect note_a =
	{
	{0,1},
	{0xFC,0x01},
	2
	};
	struct sound_effect note_a_sharp =
	{
	{0,1},
	{0xF0,0x00},
	2
	};
	struct sound_effect note_b =
	{
	{0,1},
	{0xC5,0x01},
	2
	};
	struct sound_effect no_note =
	{
	{0x00},
	{0},
	-1
	};
	/* END OCTAVE 3 */
	
	/* OCTAVE 5 */
		struct sound_effect note_c_fifth =
	{
	{0,1},
	{0xD6,0x00},
	2
	};
	struct sound_effect note_c_sharp_fifth =
	{
	{0,1},
	{0xCA,0x00},
	2
	};
	struct sound_effect note_d_fifth =
	{
	{0,1},
	{0xBE,0x00},
	2
	};
	struct sound_effect note_d_sharp_fifth =
	{
	{0,1},
	{0xB4,0x00},
	2
	};
	struct sound_effect note_e_fifth =
	{
	{0,1},
	{0xAA,0x00},
	2
	};
	struct sound_effect note_f_fifth =
	{
	{0,1},
	{0xA0,0x00},
	2
	};
	struct sound_effect note_f_sharp_fifth =
	{
	{0,1},
	{0x97,0x00},
	2
	};
	struct sound_effect note_g_fifth =
	{
	{0,1},
	{0x8F,0x00},
	2
	};
	struct sound_effect note_g_sharp_fifth =
	{
	{0,1},
	{0x87,0x00},
	2
	};
	struct sound_effect note_a_fifth =
	{
	{0,1},
	{0x7F,0x00},
	2
	};
	struct sound_effect note_a_sharp_fifth =
	{
	{0,1},
	{0x78,0x00},
	2
	};
	struct sound_effect note_b_fifth =
	{
	{0,1},
	{0xE2,0x00},
	2
	};
	/* END OCTAVE 5 */
	
	struct sound_effect note_c_and_a =
	{
	{0,1,2,3},
	{0xAC,0x01,0xFE,0x00},
	4
	};
	struct sound_effect note_c_and_f =
	{
	{0,1,2,3},
	{0xAC,0x01,0x40,0x01},
	4
	};
	struct sound_effect note_d_and_a_sharp =
	{
	{0,1,2,3},
	{0x7D,0x01,0xF0,0x00},
	4
	};
	struct sound_effect note_c_a_and_low_f =
	{
	{0,1,2,3,4,5},
	{0xAC,0x01,0xFE,0x00,0x81,0x02},
	6
	};
	struct sound_effect note_d_and_f =
	{
	{0,1,2,3},
	{0x7D,0x01,0x40,0x01},
	4
	};
	struct sound_effect note_d_and_a =
	{
	{0,1,2,3},
	{0x7D,0x01,0xFE,0x00},
	4
	};
	struct sound_effect note_a_and_f_low_sharp =
	{
	{0,1,2,3},
	{0xFE,0x00,0x5D,0x02},
	4
	};
	
	/*
	play_sound_effect(note_g,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_d_fifth,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_c_fifth,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a_sharp,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a_sharp,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_g,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a_sharp,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_c_fifth,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a_sharp,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_f,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_a,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_g,1);
	play_sound_effect(note_d,1);

	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_c_and_f,2);
	
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	
	play_sound_effect(note_c,1);
	play_sound_effect(note_c,1);
	
	play_sound_effect(note_a_sharp,1);
	play_sound_effect(note_a_sharp,1);
	
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_d_and_f,2);
	play_sound_effect(note_d_and_f,2);
	play_sound_effect(note_d_and_f,2);
	
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_a_and_f_low_sharp,2);
	play_sound_effect(note_a_and_f_low_sharp,2);
	play_sound_effect(note_a_and_f_low_sharp,2);
	
	play_sound_effect(note_d_and_a,2);
	play_sound_effect(note_d_and_a,2);
	play_sound_effect(note_d_and_a,2);
	
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	
	play_sound_effect(note_c,1);
	play_sound_effect(note_c,1);
	play_sound_effect(note_c,1);
	
	play_sound_effect(note_d,1);
	play_sound_effect(note_d,1);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_f,2);
	play_sound_effect(note_c_and_f,2);
	play_sound_effect(note_c_and_f,2);
	play_sound_effect(note_c_and_f,2);
	play_sound_effect(note_c_and_f,2);
	
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d,1);
	
	play_sound_effect(note_c_and_f,2);
	play_sound_effect(note_c_and_f,2);
	
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_c_and_f,2);
	
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	
	play_sound_effect(note_c,1);
	play_sound_effect(note_c,1);
	play_sound_effect(note_c,1);
	
	play_sound_effect(note_a_sharp,1);
	play_sound_effect(note_a_sharp,1);
	play_sound_effect(note_a_sharp,1);
	
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_d_and_f,2);
	play_sound_effect(note_d_and_f,2);
	play_sound_effect(note_d_and_f,2);
	play_sound_effect(note_d_and_f,2);
	
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_a_and_f_low_sharp,2);
	play_sound_effect(note_a_and_f_low_sharp,2);
	play_sound_effect(note_a_and_f_low_sharp,2);
	
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	play_sound_effect(note_c_and_a,2);
	
	play_sound_effect(note_c_and_f,2);
	
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	play_sound_effect(note_d_and_a_sharp,2);
	*/
}