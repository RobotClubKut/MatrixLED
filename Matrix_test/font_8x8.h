/****************************************************************************/
/* �Ώۃ}�C�R�� R8C/M12A                                                    */
/* ̧�ٓ��e     �O���t�B�b�N�t�����䃉�C�u�����p�t�H���g�f�[�^              */
/* �o�[�W����   Ver.1.00                                                    */
/* Date         2012.04.27                                                  */
/* Copyright    ���l�T�X�}�C�R���J�[�����[������                            */
/****************************************************************************/

/*
�{�L�����N�^�f�[�^�́A
8�~8 �h�b�g���{���t�H���g�u�����t�H���g�v
http://www.geocities.jp/littlimi/font.htm
��16�i���f�[�^�ɕϊ����Ďg�p���Ă��܂��B
�t���[�Œ񋟂����Ă������^�Ȃޗl�ɂ͂����\���グ�܂��B
*/

// �L�����N�^�f�[�^ 0x20�`0xfd
const char font[] = {
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x20 '�@'
0x00,0x00,0x00,0x5f,0x00,0x00,0x00,0x00,    // 0x21 '�I'
0x05,0x03,0x00,0x05,0x03,0x00,0x00,0x00,    // 0x22 '�h'
0x20,0x62,0x3e,0x63,0x3e,0x23,0x02,0x00,    // 0x23 '��'
0x00,0x24,0x2a,0x7a,0x2f,0x2a,0x12,0x00,    // 0x24 '��'
0x42,0x25,0x12,0x08,0x24,0x52,0x21,0x00,    // 0x25 '��'
0x20,0x56,0x49,0x55,0x22,0x58,0x40,0x00,    // 0x26 '��'
0x04,0x03,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x27 '�f'
0x00,0x00,0x00,0x3e,0x22,0x41,0x41,0x00,    // 0x28 '�i'
0x41,0x41,0x22,0x3e,0x00,0x00,0x00,0x00,    // 0x29 '�j'
0x00,0x22,0x14,0x7f,0x14,0x22,0x00,0x00,    // 0x2a '��'
0x08,0x08,0x08,0x7f,0x08,0x08,0x08,0x00,    // 0x2b '�{'
0x50,0x30,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x2c '�C'
0x08,0x08,0x08,0x08,0x08,0x08,0x08,0x08,    // 0x2d '�|'
0x60,0x60,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x2e '�D'
0x40,0x20,0x10,0x08,0x04,0x02,0x01,0x00,    // 0x2f '�^'
0x00,0x3e,0x41,0x41,0x41,0x41,0x3e,0x00,    // 0x30 '�O'
0x00,0x00,0x42,0x7f,0x40,0x00,0x00,0x00,    // 0x31 '�P'
0x00,0x62,0x51,0x51,0x49,0x49,0x46,0x00,    // 0x32 '�Q'
0x00,0x22,0x41,0x49,0x49,0x49,0x36,0x00,    // 0x33 '�R'
0x00,0x30,0x28,0x24,0x22,0x7f,0x20,0x00,    // 0x34 '�S'
0x00,0x2f,0x45,0x45,0x45,0x45,0x39,0x00,    // 0x35 '�T'
0x00,0x3e,0x49,0x49,0x49,0x49,0x32,0x00,    // 0x36 '�U'
0x00,0x01,0x01,0x61,0x19,0x05,0x03,0x00,    // 0x37 '�V'
0x00,0x36,0x49,0x49,0x49,0x49,0x36,0x00,    // 0x38 '�W'
0x00,0x26,0x49,0x49,0x49,0x49,0x3e,0x00,    // 0x39 '�X'
0x00,0x00,0x36,0x36,0x00,0x00,0x00,0x00,    // 0x3a '�F'
0x00,0x00,0x56,0x36,0x00,0x00,0x00,0x00,    // 0x3b '�G'
0x00,0x00,0x00,0x08,0x14,0x22,0x41,0x00,    // 0x3c '��'
0x14,0x14,0x14,0x14,0x14,0x14,0x14,0x00,    // 0x3d '��'
0x41,0x22,0x14,0x08,0x00,0x00,0x00,0x00,    // 0x3e '��'
0x00,0x02,0x01,0x51,0x09,0x09,0x06,0x00,    // 0x3f '�H'
0x1c,0x22,0x59,0x55,0x4d,0x12,0x0c,0x00,    // 0x40 '��'
0x60,0x18,0x16,0x11,0x16,0x18,0x60,0x00,    // 0x41 '�`'
0x00,0x7f,0x49,0x49,0x49,0x49,0x36,0x00,    // 0x42 '�a'
0x00,0x1c,0x22,0x41,0x41,0x41,0x22,0x00,    // 0x43 '�b'
0x00,0x7f,0x41,0x41,0x41,0x22,0x1c,0x00,    // 0x44 '�c'
0x00,0x7f,0x49,0x49,0x49,0x49,0x41,0x00,    // 0x45 '�d'
0x00,0x7f,0x09,0x09,0x09,0x09,0x01,0x00,    // 0x46 '�e'
0x00,0x1c,0x22,0x41,0x49,0x49,0x3a,0x00,    // 0x47 '�f'
0x00,0x7f,0x08,0x08,0x08,0x08,0x7f,0x00,    // 0x48 '�g'
0x00,0x00,0x41,0x7f,0x41,0x00,0x00,0x00,    // 0x49 '�h'
0x00,0x20,0x40,0x40,0x40,0x40,0x3f,0x00,    // 0x4a '�i'
0x00,0x7f,0x10,0x08,0x14,0x22,0x41,0x00,    // 0x4b '�j'
0x00,0x7f,0x40,0x40,0x40,0x40,0x40,0x00,    // 0x4c '�k'
0x7f,0x02,0x0c,0x30,0x0c,0x02,0x7f,0x00,    // 0x4d '�l'
0x00,0x7f,0x02,0x04,0x08,0x10,0x7f,0x00,    // 0x4e '�m'
0x00,0x1c,0x22,0x41,0x41,0x22,0x1c,0x00,    // 0x4f '�n'
0x00,0x7f,0x09,0x09,0x09,0x09,0x06,0x00,    // 0x50 '�o'
0x00,0x1c,0x22,0x41,0x51,0x22,0x5c,0x00,    // 0x51 '�p'
0x00,0x7f,0x09,0x09,0x19,0x29,0x46,0x00,    // 0x52 '�q'
0x00,0x26,0x49,0x49,0x49,0x49,0x32,0x00,    // 0x53 '�r'
0x01,0x01,0x01,0x7f,0x01,0x01,0x01,0x00,    // 0x54 '�s'
0x00,0x3f,0x40,0x40,0x40,0x40,0x3f,0x00,    // 0x55 '�t'
0x03,0x0c,0x30,0x40,0x30,0x0c,0x03,0x00,    // 0x56 '�u'
0x1f,0x60,0x18,0x06,0x18,0x60,0x1f,0x00,    // 0x57 '�v'
0x41,0x22,0x14,0x08,0x14,0x22,0x41,0x00,    // 0x58 '�w'
0x01,0x02,0x04,0x78,0x04,0x02,0x01,0x00,    // 0x59 '�x'
0x00,0x41,0x61,0x51,0x49,0x45,0x43,0x00,    // 0x5a '�y'
0x00,0x00,0x00,0x00,0x7f,0x41,0x41,0x00,    // 0x5b '�m'
0x00,0x2b,0x2c,0x78,0x2c,0x2b,0x00,0x00,    // 0x5c '��'
0x41,0x41,0x7f,0x00,0x00,0x00,0x00,0x00,    // 0x5d '�n'
0x00,0x00,0x02,0x01,0x02,0x00,0x00,0x00,    // 0x5e '�O'
0x40,0x40,0x40,0x40,0x40,0x40,0x40,0x00,    // 0x5f '�Q'
0x05,0x03,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x60 '�M'
0x00,0x20,0x54,0x54,0x54,0x78,0x00,0x00,    // 0x61 '��'
0x00,0x7f,0x48,0x44,0x44,0x38,0x00,0x00,    // 0x62 '��'
0x00,0x38,0x44,0x44,0x44,0x28,0x00,0x00,    // 0x63 '��'
0x00,0x38,0x44,0x44,0x48,0x7f,0x00,0x00,    // 0x64 '��'
0x00,0x38,0x54,0x54,0x54,0x18,0x00,0x00,    // 0x65 '��'
0x00,0x00,0x04,0x7e,0x05,0x01,0x00,0x00,    // 0x66 '��'
0x00,0x08,0x54,0x54,0x54,0x3c,0x00,0x00,    // 0x67 '��'
0x00,0x7f,0x08,0x04,0x04,0x78,0x00,0x00,    // 0x68 '��'
0x00,0x00,0x00,0x7d,0x00,0x00,0x00,0x00,    // 0x69 '��'
0x00,0x20,0x40,0x40,0x3d,0x00,0x00,0x00,    // 0x6a '��'
0x00,0x00,0x7f,0x10,0x28,0x44,0x00,0x00,    // 0x6b '��'
0x00,0x00,0x01,0x7f,0x00,0x00,0x00,0x00,    // 0x6c '��'
0x00,0x7c,0x04,0x78,0x04,0x78,0x00,0x00,    // 0x6d '��'
0x00,0x7c,0x08,0x04,0x04,0x78,0x00,0x00,    // 0x6e '��'
0x00,0x38,0x44,0x44,0x44,0x38,0x00,0x00,    // 0x6f '��'
0x00,0x7c,0x14,0x14,0x14,0x08,0x00,0x00,    // 0x70 '��'
0x00,0x08,0x14,0x14,0x14,0x7c,0x00,0x00,    // 0x71 '��'
0x00,0x7c,0x08,0x04,0x04,0x08,0x00,0x00,    // 0x72 '��'
0x00,0x48,0x54,0x54,0x54,0x24,0x00,0x00,    // 0x73 '��'
0x00,0x04,0x3e,0x44,0x44,0x20,0x00,0x00,    // 0x74 '��'
0x00,0x3c,0x40,0x40,0x20,0x7c,0x00,0x00,    // 0x75 '��'
0x00,0x0c,0x30,0x40,0x30,0x0c,0x00,0x00,    // 0x76 '��'
0x00,0x1c,0x60,0x18,0x60,0x1c,0x00,0x00,    // 0x77 '��'
0x00,0x44,0x28,0x10,0x28,0x44,0x00,0x00,    // 0x78 '��'
0x00,0x44,0x58,0x20,0x18,0x04,0x00,0x00,    // 0x79 '��'
0x00,0x44,0x64,0x54,0x4c,0x44,0x00,0x00,    // 0x7a '��'
0x00,0x00,0x00,0x08,0x36,0x41,0x41,0x00,    // 0x7b '�o'
0x00,0x00,0x00,0x7f,0x00,0x00,0x00,0x00,    // 0x7c '�b'
0x41,0x41,0x36,0x08,0x00,0x00,0x00,0x00,    // 0x7d '�p'
0x08,0x04,0x04,0x08,0x10,0x10,0x08,0x00,    // 0x7e '�`'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x7f '�@'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x80 '�@'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x81 '�@'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x82 '�@'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x83 '�@'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x84 '�@'
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0x85 '�@'
0x10,0x0a,0x2e,0x5b,0x72,0x4a,0x48,0x00,    // 0x86 '��'(�Ǝ�)
0x00,0x20,0x54,0x7e,0x34,0x14,0x60,0x00,    // 0x87 '��'(�Ǝ�)
0x00,0x3c,0x40,0x20,0x04,0x18,0x00,0x00,    // 0x88 '��'(�Ǝ�)
0x00,0x10,0x4a,0x4a,0x2a,0x10,0x00,0x00,    // 0x89 '��'(�Ǝ�)
0x00,0x48,0x2a,0x3a,0x4a,0x40,0x00,0x00,    // 0x8a '��'(�Ǝ�)
0x00,0x24,0x7e,0x14,0x50,0x24,0x00,0x00,    // 0x8b '��'(�Ǝ�)
0x00,0x08,0x0e,0x38,0x46,0x14,0x08,0x00,    // 0x8c '��'(�Ǝ�)
0x00,0x1c,0x48,0x3e,0x24,0x18,0x00,0x00,    // 0x8d '��'(�Ǝ�)
0x00,0x20,0x50,0x50,0x3e,0x48,0x00,0x00,    // 0x8e '��'(�Ǝ�)
0x00,0x10,0x10,0x48,0x48,0x30,0x00,0x00,    // 0x8f '��'(�Ǝ�)
0x04,0x08,0x08,0x08,0x08,0x08,0x08,0x00,    // 0x90 '�['(�Ǝ�)
0x20,0x52,0x7f,0x2a,0x1a,0x4a,0x30,0x00,    // 0x91 '��'(�Ǝ�)
0x1e,0x20,0x40,0x20,0x02,0x04,0x18,0x00,    // 0x92 '��'(�Ǝ�)
0x00,0x08,0x45,0x45,0x45,0x25,0x18,0x00,    // 0x93 '��'(�Ǝ�)
0x00,0x44,0x25,0x15,0x3d,0x45,0x40,0x00,    // 0x94 '��'(�Ǝ�)
0x22,0x52,0x7f,0x0a,0x48,0x4a,0x34,0x00,    // 0x95 '��'(�Ǝ�)
0x44,0x34,0x4f,0x44,0x38,0x04,0x18,0x00,    // 0x96 '��'(�Ǝ�)
0x00,0x2a,0x5a,0x4b,0x4e,0x5a,0x08,0x00,    // 0x97 '��'(�Ǝ�)
0x00,0x08,0x14,0x14,0x22,0x41,0x00,0x00,    // 0x98 '��'(�Ǝ�)
0x3f,0x00,0x04,0x44,0x3f,0x04,0x04,0x00,    // 0x99 '��'(�Ǝ�)
0x00,0x20,0x52,0x42,0x42,0x42,0x40,0x00,    // 0x9a '��'(�Ǝ�)
0x00,0x24,0x54,0x44,0x47,0x5c,0x04,0x00,    // 0x9b '��'(�Ǝ�)
0x00,0x00,0x3f,0x40,0x40,0x40,0x20,0x00,    // 0x9c '��'(�Ǝ�)
0x02,0x02,0x0a,0x56,0x3f,0x02,0x02,0x00,    // 0x9d '��'(�Ǝ�)
0x04,0x04,0x3f,0x44,0x54,0x5f,0x44,0x00,    // 0x9e '��'(�Ǝ�)
0x00,0x08,0x09,0x3d,0x4b,0x49,0x08,0x00,    // 0x9f '��'(�Ǝ�)
0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,    // 0xa0 '�@'
0x20,0x50,0x20,0x00,0x00,0x00,0x00,0x00,    // 0xa1 '�B'
0x00,0x00,0x00,0x3f,0x01,0x01,0x01,0x00,    // 0xa2 '�u'
0x40,0x40,0x40,0x7e,0x00,0x00,0x00,0x00,    // 0xa3 '�v'
0x20,0x40,0x00,0x00,0x00,0x00,0x00,0x00,    // 0xa4 '�A'
0x00,0x00,0x18,0x18,0x00,0x00,0x00,0x00,    // 0xa5 '�E'
0x00,0x01,0x45,0x45,0x25,0x15,0x0f,0x00,    // 0xa6 '��'
0x00,0x04,0x44,0x3c,0x14,0x0c,0x00,0x00,    // 0xa7 '�@'
0x00,0x20,0x20,0x10,0x78,0x04,0x00,0x00,    // 0xa8 '�B'
0x00,0x18,0x48,0x4c,0x28,0x18,0x00,0x00,    // 0xa9 '�D'
0x00,0x40,0x48,0x78,0x48,0x40,0x00,0x00,    // 0xaa '�F'
0x00,0x28,0x28,0x58,0x7c,0x08,0x00,0x00,    // 0xab '�H'
0x00,0x10,0x1c,0x68,0x08,0x18,0x00,0x00,    // 0xac '��'
0x00,0x40,0x48,0x48,0x78,0x40,0x00,0x00,    // 0xad '��'
0x00,0x00,0x44,0x54,0x54,0x7c,0x00,0x00,    // 0xae '��'
0x00,0x18,0x40,0x58,0x20,0x18,0x00,0x00,    // 0xaf '�b'
0x04,0x08,0x08,0x08,0x08,0x08,0x08,0x00,    // 0xb0 '�['
0x00,0x01,0x41,0x3d,0x09,0x05,0x03,0x00,    // 0xb1 '�A'
0x00,0x10,0x10,0x08,0x7c,0x02,0x01,0x00,    // 0xb2 '�C'
0x00,0x06,0x42,0x43,0x22,0x12,0x0e,0x00,    // 0xb3 '�E'
0x20,0x22,0x22,0x3e,0x22,0x22,0x20,0x00,    // 0xb4 '�G'
0x22,0x22,0x12,0x4a,0x7f,0x02,0x02,0x00,    // 0xb5 '�I'
0x00,0x42,0x22,0x1f,0x02,0x42,0x7e,0x00,    // 0xb6 '�J'
0x00,0x12,0x12,0x1f,0x72,0x12,0x10,0x00,    // 0xb7 '�L'
0x00,0x08,0x44,0x43,0x22,0x12,0x0e,0x00,    // 0xb8 '�N'
0x08,0x07,0x42,0x22,0x1e,0x02,0x02,0x00,    // 0xb9 '�P'
0x00,0x42,0x42,0x42,0x42,0x42,0x7e,0x00,    // 0xba '�R'
0x02,0x02,0x4f,0x42,0x22,0x1f,0x02,0x00,    // 0xbb '�T'
0x00,0x45,0x4a,0x40,0x20,0x10,0x0c,0x00,    // 0xbc '�V'
0x40,0x42,0x22,0x22,0x1a,0x26,0x40,0x00,    // 0xbd '�X'
0x04,0x04,0x3f,0x44,0x44,0x54,0x4c,0x00,    // 0xbe '�Z'
0x00,0x01,0x46,0x40,0x20,0x10,0x0f,0x00,    // 0xbf '�\'
0x00,0x08,0x44,0x4b,0x2a,0x12,0x0e,0x00,    // 0xc0 '�^'
0x08,0x0a,0x4a,0x3e,0x09,0x09,0x08,0x00,    // 0xc1 '�`'
0x02,0x0c,0x42,0x4c,0x20,0x10,0x0e,0x00,    // 0xc2 '�c'
0x04,0x05,0x45,0x3d,0x05,0x05,0x04,0x00,    // 0xc3 '�e'
0x00,0x00,0x7f,0x08,0x08,0x10,0x00,0x00,    // 0xc4 '�g'
0x04,0x44,0x24,0x1f,0x04,0x04,0x04,0x00,    // 0xc5 '�i'
0x20,0x22,0x22,0x22,0x22,0x22,0x20,0x00,    // 0xc6 '�j'
0x40,0x41,0x25,0x15,0x19,0x27,0x00,0x00,    // 0xc7 '�k'
0x20,0x22,0x12,0x7b,0x06,0x12,0x20,0x00,    // 0xc8 '�l'
0x40,0x40,0x20,0x10,0x08,0x07,0x00,0x00,    // 0xc9 '�m'
0x40,0x30,0x0e,0x00,0x02,0x0c,0x70,0x00,    // 0xca '�n'
0x00,0x3f,0x48,0x48,0x48,0x44,0x44,0x00,    // 0xcb '�q'
0x00,0x02,0x42,0x42,0x22,0x12,0x0e,0x00,    // 0xcc '�t'
0x08,0x04,0x02,0x04,0x08,0x10,0x20,0x00,    // 0xcd '�w'
0x24,0x14,0x44,0x7f,0x04,0x14,0x24,0x00,    // 0xce '�z'
0x02,0x02,0x12,0x22,0x52,0x0a,0x06,0x00,    // 0xcf '�}'
0x00,0x21,0x25,0x29,0x4a,0x42,0x00,0x00,    // 0xd0 '�~'
0x40,0x70,0x4c,0x43,0x50,0x20,0x40,0x00,    // 0xd1 '��'
0x40,0x44,0x24,0x14,0x08,0x37,0x00,0x00,    // 0xd2 '��'
0x00,0x08,0x09,0x3f,0x49,0x49,0x48,0x00,    // 0xd3 '��'
0x04,0x04,0x0f,0x74,0x02,0x0a,0x06,0x00,    // 0xd4 '��'
0x20,0x22,0x22,0x22,0x3e,0x20,0x20,0x00,    // 0xd5 '��'
0x00,0x42,0x4a,0x4a,0x4a,0x4a,0x7e,0x00,    // 0xd6 '��'
0x00,0x04,0x45,0x45,0x25,0x15,0x0c,0x00,    // 0xd7 '��'
0x00,0x0f,0x40,0x40,0x20,0x1f,0x00,0x00,    // 0xd8 '��'
0x40,0x20,0x1e,0x00,0x7f,0x20,0x10,0x00,    // 0xd9 '��'
0x00,0x00,0x7f,0x40,0x20,0x10,0x08,0x00,    // 0xda '��'
0x00,0x7e,0x42,0x42,0x42,0x42,0x7e,0x00,    // 0xdb '��'
0x00,0x06,0x42,0x42,0x22,0x12,0x0e,0x00,    // 0xdc '��'
0x00,0x41,0x42,0x40,0x20,0x10,0x0c,0x00,    // 0xdd '��'
0x01,0x02,0x01,0x02,0x00,0x00,0x00,0x00,    // 0xde '�J'
0x02,0x05,0x02,0x00,0x00,0x00,0x00,0x00,    // 0xdf '�K'
0x42,0x3a,0x07,0x22,0x54,0x44,0x44,0x00,    // 0xe0 '��'(�Ǝ�)
0x00,0x02,0x12,0x4e,0x4b,0x4a,0x32,0x00,    // 0xe1 '��'(�Ǝ�)
0x04,0x04,0x02,0x22,0x22,0x22,0x1c,0x00,    // 0xe2 '��'(�Ǝ�)
0x00,0x02,0x02,0x1a,0x25,0x43,0x41,0x00,    // 0xe3 '��'(�Ǝ�)
0x00,0x20,0x57,0x48,0x48,0x44,0x44,0x00,    // 0xe4 '��'(�Ǝ�)
0x12,0x0a,0x27,0x52,0x50,0x3a,0x24,0x00,    // 0xe5 '��'(�Ǝ�)
0x7f,0x00,0x20,0x52,0x42,0x42,0x40,0x00,    // 0xe6 '��'(�Ǝ�)
0x30,0x4e,0x38,0x54,0x0f,0x64,0x78,0x00,    // 0xe7 '��'(�Ǝ�)
0x24,0x14,0x7f,0x04,0x22,0x52,0x3c,0x00,    // 0xe8 '��'(�Ǝ�)
0x18,0x24,0x12,0x4e,0x42,0x24,0x18,0x00,    // 0xe9 '��'(�Ǝ�)
0x7f,0x00,0x24,0x54,0x54,0x3f,0x44,0x00,    // 0xea '��'(�Ǝ�)
0x02,0x3a,0x47,0x40,0x41,0x3e,0x04,0x00,    // 0xeb '��'(�Ǝ�)
0x40,0x30,0x40,0x4d,0x32,0x10,0x60,0x00,    // 0xec '��'(�Ǝ�)
0x08,0x04,0x02,0x04,0x08,0x10,0x10,0x00,    // 0xed '��'(�Ǝ�)
0x7f,0x00,0x6a,0x6a,0x7e,0x2a,0x4a,0x00,    // 0xee '��'(�Ǝ�)
0x00,0x6a,0x6a,0x6a,0x7f,0x2a,0x4a,0x00,    // 0xef '��'(�Ǝ�)
0x30,0x29,0x1d,0x4b,0x48,0x3c,0x10,0x00,    // 0xf0 '��'(�Ǝ�)
0x12,0x2a,0x7f,0x42,0x40,0x42,0x24,0x00,    // 0xf1 '��'(�Ǝ�)
0x30,0x4e,0x38,0x54,0x0f,0x44,0x38,0x00,    // 0xf2 '��'(�Ǝ�)
0x00,0x0a,0x3e,0x4b,0x4a,0x4a,0x30,0x00,    // 0xf3 '��'(�Ǝ�)
0x04,0x07,0x1c,0x62,0x03,0x0a,0x04,0x00,    // 0xf4 '��'(�Ǝ�)
0x1e,0x04,0x52,0x3f,0x12,0x12,0x0c,0x00,    // 0xf5 '��'(�Ǝ�)
0x00,0x20,0x50,0x50,0x3f,0x24,0x44,0x00,    // 0xf6 '��'(�Ǝ�)
0x00,0x1c,0x51,0x49,0x4a,0x48,0x30,0x00,    // 0xf7 '��'(�Ǝ�)
0x00,0x0f,0x42,0x41,0x21,0x1e,0x00,0x00,    // 0xf8 '��'(�Ǝ�)
0x00,0x10,0x69,0x6d,0x4b,0x49,0x30,0x00,    // 0xf9 '��'(�Ǝ�)
0x24,0x14,0x7f,0x04,0x02,0x3e,0x40,0x00,    // 0xfa '��'(�Ǝ�)
0x00,0x10,0x49,0x4d,0x4b,0x49,0x30,0x00,    // 0xfb '��'(�Ǝ�)
0x24,0x14,0x7f,0x04,0x42,0x42,0x3c,0x00,    // 0xfc '��'(�Ǝ�)
0x40,0x30,0x0c,0x33,0x40,0x40,0x20,0x00,    // 0xfd '��'(�Ǝ�)
};

