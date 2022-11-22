#pragma once

/**
 * @brief Przechowuje wsp�rz�dne dw�ch punkt�w
 */
class Vector4d
{
public:
	/**
	 * @brief Wektor 4d
	 * 
	 * \param px1 Wsp�rz�dna x dla punktu 1
	 * \param py1 Wsp�rz�dna y dla punktu 1
	 * \param px2 Wsp�rz�dna x dla punktu 2
	 * \param py2 Wsp�rz�dna y dla punktu 2
	 */
	Vector4d(int px1, int py1, int px2,int py2);

	int px1;/*!< Wsp�rz�dna x dla punktu 1>*/
	int py1;/*!<>*/
	int px2;/*!<>*/
	int py2;/*!<>*/

	/**
	 * @brief Setter wektor 
	 * 
	 * \param px1 Ustawia wsp�rz�dn� x dla punktu 1
	 * \param py1 Ustawia wsp�rz�dn� y dla punktu 1
	 * \param px2 Ustawia wsp�rz�dn� x dla punktu 2
	 * \param py2 Ustawia wsp�rz�dn� y dla punktu 2
	 */
	void setValues(int px1, int py1, int px2, int py2);

};

