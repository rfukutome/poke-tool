#pragma once

#include <fstream>
#include <string>
#include <iostream>
#include <msclr/marshal_cppstd.h>

#include "PokemonListReader.h"

namespace PokeTool {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

    PokemonListReader pokemonDatabase;

	/// <summary>
	/// Summary for MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
            populatePokemonLists();

		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}
    private: System::Windows::Forms::PictureBox^  normalImage;
    protected:

    private: System::Windows::Forms::ComboBox^  pokemonNumber;
    private: System::Windows::Forms::ComboBox^  pokemonName;
    private: System::Windows::Forms::Label^  pokemonNameText;
    private: System::Windows::Forms::Label^  pokemonNumberText;
    private: System::Windows::Forms::PictureBox^  typeImage1;
    private: System::Windows::Forms::PictureBox^  typeImage2;
    private: System::Windows::Forms::PictureBox^  fireImage;
    private: System::Windows::Forms::PictureBox^  waterImage;
    private: System::Windows::Forms::PictureBox^  electricImage;
    private: System::Windows::Forms::PictureBox^  grassImage;
    private: System::Windows::Forms::PictureBox^  iceImage;
    private: System::Windows::Forms::PictureBox^  fightingImage;
    private: System::Windows::Forms::PictureBox^  poisonImage;
    private: System::Windows::Forms::PictureBox^  groundImage;
    private: System::Windows::Forms::PictureBox^  flyingImage;
    private: System::Windows::Forms::PictureBox^  psychicImage;
    private: System::Windows::Forms::PictureBox^  bugImage;
    private: System::Windows::Forms::PictureBox^  rockImage;
    private: System::Windows::Forms::PictureBox^  ghostImage;
    private: System::Windows::Forms::PictureBox^  dragonImage;
    private: System::Windows::Forms::PictureBox^  darkImage;
    private: System::Windows::Forms::PictureBox^  steelImage;
    private: System::Windows::Forms::PictureBox^  fairyImage;
    private: System::Windows::Forms::GroupBox^  groupBox1;
    private: System::Windows::Forms::Label^  fireLabel;
    private: System::Windows::Forms::Label^  normalLabel;
    private: System::Windows::Forms::Label^  fairyLabel;
    private: System::Windows::Forms::Label^  steelLabel;
    private: System::Windows::Forms::Label^  darkLabel;
    private: System::Windows::Forms::Label^  dragonLabel;
    private: System::Windows::Forms::Label^  ghostLabel;
    private: System::Windows::Forms::Label^  rockLabel;
    private: System::Windows::Forms::Label^  bugLabel;
    private: System::Windows::Forms::Label^  psychicLabel;
    private: System::Windows::Forms::Label^  flyingLabel;
    private: System::Windows::Forms::Label^  groundLabel;
    private: System::Windows::Forms::Label^  poisonLabel;
    private: System::Windows::Forms::Label^  fightingLabel;
    private: System::Windows::Forms::Label^  iceLabel;
    private: System::Windows::Forms::Label^  grassLabel;
    private: System::Windows::Forms::Label^  electricLabel;
    private: System::Windows::Forms::Label^  waterLabel;

    protected:

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

        void populatePokemonLists()
        {
            std::ifstream pokemon("pokemon.txt");
            std::string number;
            std::string name;
            std::string type;
            std::string type2;

            while (pokemon >> number >> name >> type >> type2)
            {
                pokemonDatabase.addPokemonData(number, name, type, type2);
                System::String^ pokeName = gcnew String(name.c_str());
                System::String^ pokeNumber = gcnew String(number.c_str());
                pokemonName->Items->Add(pokeName);
                pokemonNumber->Items->Add(pokeNumber);
            }
            pokemonName->SelectedIndex = 0;
        };

        void setPokemonWeakness(float* argWeakness) {
            normalLabel->Text = gcnew String((std::to_string(argWeakness[NORMAL])).c_str());
            fireLabel->Text = gcnew String((std::to_string(argWeakness[FIRE])).c_str());
            waterLabel->Text = gcnew String((std::to_string(argWeakness[WATER])).c_str());
            electricLabel->Text = gcnew String((std::to_string(argWeakness[ELECTRIC])).c_str());
            grassLabel->Text = gcnew String((std::to_string(argWeakness[GRASS])).c_str());
            iceLabel->Text = gcnew String((std::to_string(argWeakness[ICE])).c_str());
            fightingLabel->Text = gcnew String((std::to_string(argWeakness[FIGHTING])).c_str());
            poisonLabel->Text = gcnew String((std::to_string(argWeakness[POISON])).c_str());
            groundLabel->Text = gcnew String((std::to_string(argWeakness[GROUND])).c_str());
            flyingLabel->Text = gcnew String((std::to_string(argWeakness[FLYING])).c_str());
            psychicLabel->Text = gcnew String((std::to_string(argWeakness[PSYCHIC])).c_str());
            bugLabel->Text = gcnew String((std::to_string(argWeakness[BUG])).c_str());
            rockLabel->Text = gcnew String((std::to_string(argWeakness[ROCK])).c_str());
            ghostLabel->Text = gcnew String((std::to_string(argWeakness[GHOST])).c_str());
            dragonLabel->Text = gcnew String((std::to_string(argWeakness[DRAGON])).c_str());
            darkLabel->Text = gcnew String((std::to_string(argWeakness[DARK])).c_str());
            steelLabel->Text = gcnew String((std::to_string(argWeakness[STEEL])).c_str());
            fairyLabel->Text = gcnew String((std::to_string(argWeakness[FAIRY])).c_str());
        }

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
            System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
            this->normalImage = (gcnew System::Windows::Forms::PictureBox());
            this->pokemonNumber = (gcnew System::Windows::Forms::ComboBox());
            this->pokemonName = (gcnew System::Windows::Forms::ComboBox());
            this->pokemonNameText = (gcnew System::Windows::Forms::Label());
            this->pokemonNumberText = (gcnew System::Windows::Forms::Label());
            this->typeImage1 = (gcnew System::Windows::Forms::PictureBox());
            this->typeImage2 = (gcnew System::Windows::Forms::PictureBox());
            this->fireImage = (gcnew System::Windows::Forms::PictureBox());
            this->waterImage = (gcnew System::Windows::Forms::PictureBox());
            this->electricImage = (gcnew System::Windows::Forms::PictureBox());
            this->grassImage = (gcnew System::Windows::Forms::PictureBox());
            this->iceImage = (gcnew System::Windows::Forms::PictureBox());
            this->fightingImage = (gcnew System::Windows::Forms::PictureBox());
            this->poisonImage = (gcnew System::Windows::Forms::PictureBox());
            this->groundImage = (gcnew System::Windows::Forms::PictureBox());
            this->flyingImage = (gcnew System::Windows::Forms::PictureBox());
            this->psychicImage = (gcnew System::Windows::Forms::PictureBox());
            this->bugImage = (gcnew System::Windows::Forms::PictureBox());
            this->rockImage = (gcnew System::Windows::Forms::PictureBox());
            this->ghostImage = (gcnew System::Windows::Forms::PictureBox());
            this->dragonImage = (gcnew System::Windows::Forms::PictureBox());
            this->darkImage = (gcnew System::Windows::Forms::PictureBox());
            this->steelImage = (gcnew System::Windows::Forms::PictureBox());
            this->fairyImage = (gcnew System::Windows::Forms::PictureBox());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->fairyLabel = (gcnew System::Windows::Forms::Label());
            this->steelLabel = (gcnew System::Windows::Forms::Label());
            this->darkLabel = (gcnew System::Windows::Forms::Label());
            this->dragonLabel = (gcnew System::Windows::Forms::Label());
            this->ghostLabel = (gcnew System::Windows::Forms::Label());
            this->rockLabel = (gcnew System::Windows::Forms::Label());
            this->bugLabel = (gcnew System::Windows::Forms::Label());
            this->psychicLabel = (gcnew System::Windows::Forms::Label());
            this->flyingLabel = (gcnew System::Windows::Forms::Label());
            this->groundLabel = (gcnew System::Windows::Forms::Label());
            this->poisonLabel = (gcnew System::Windows::Forms::Label());
            this->fightingLabel = (gcnew System::Windows::Forms::Label());
            this->iceLabel = (gcnew System::Windows::Forms::Label());
            this->grassLabel = (gcnew System::Windows::Forms::Label());
            this->electricLabel = (gcnew System::Windows::Forms::Label());
            this->waterLabel = (gcnew System::Windows::Forms::Label());
            this->normalLabel = (gcnew System::Windows::Forms::Label());
            this->fireLabel = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->normalImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->typeImage1))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->typeImage2))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fireImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->waterImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->electricImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grassImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iceImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fightingImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->poisonImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groundImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flyingImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->psychicImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bugImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rockImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ghostImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dragonImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->darkImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->steelImage))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fairyImage))->BeginInit();
            this->groupBox1->SuspendLayout();
            this->SuspendLayout();
            // 
            // normalImage
            // 
            this->normalImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"normalImage.BackgroundImage")));
            this->normalImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->normalImage->Location = System::Drawing::Point(37, 34);
            this->normalImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->normalImage->Name = L"normalImage";
            this->normalImage->Size = System::Drawing::Size(60, 21);
            this->normalImage->TabIndex = 0;
            this->normalImage->TabStop = false;
            // 
            // pokemonNumber
            // 
            this->pokemonNumber->Cursor = System::Windows::Forms::Cursors::Default;
            this->pokemonNumber->DropDownHeight = 150;
            this->pokemonNumber->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pokemonNumber->FormattingEnabled = true;
            this->pokemonNumber->IntegralHeight = false;
            this->pokemonNumber->Location = System::Drawing::Point(73, 37);
            this->pokemonNumber->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->pokemonNumber->Name = L"pokemonNumber";
            this->pokemonNumber->Size = System::Drawing::Size(62, 28);
            this->pokemonNumber->TabIndex = 1;
            this->pokemonNumber->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::pokemonNumber_SelectedIndexChanged);
            // 
            // pokemonName
            // 
            this->pokemonName->AutoCompleteMode = System::Windows::Forms::AutoCompleteMode::SuggestAppend;
            this->pokemonName->AutoCompleteSource = System::Windows::Forms::AutoCompleteSource::ListItems;
            this->pokemonName->DropDownHeight = 150;
            this->pokemonName->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pokemonName->FormattingEnabled = true;
            this->pokemonName->IntegralHeight = false;
            this->pokemonName->Location = System::Drawing::Point(141, 36);
            this->pokemonName->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->pokemonName->Name = L"pokemonName";
            this->pokemonName->Size = System::Drawing::Size(151, 28);
            this->pokemonName->TabIndex = 2;
            this->pokemonName->SelectedIndexChanged += gcnew System::EventHandler(this, &MyForm::pokemonName_SelectedIndexChanged);
            // 
            // pokemonNameText
            // 
            this->pokemonNameText->AutoSize = true;
            this->pokemonNameText->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->pokemonNameText->Location = System::Drawing::Point(141, 15);
            this->pokemonNameText->Name = L"pokemonNameText";
            this->pokemonNameText->Size = System::Drawing::Size(78, 18);
            this->pokemonNameText->TabIndex = 3;
            this->pokemonNameText->Text = L"POKEMON";
            // 
            // pokemonNumberText
            // 
            this->pokemonNumberText->AutoSize = true;
            this->pokemonNumberText->Location = System::Drawing::Point(85, 15);
            this->pokemonNumberText->Name = L"pokemonNumberText";
            this->pokemonNumberText->Size = System::Drawing::Size(14, 13);
            this->pokemonNumberText->TabIndex = 4;
            this->pokemonNumberText->Text = L"#";
            // 
            // typeImage1
            // 
            this->typeImage1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->typeImage1->Location = System::Drawing::Point(298, 36);
            this->typeImage1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->typeImage1->Name = L"typeImage1";
            this->typeImage1->Size = System::Drawing::Size(88, 29);
            this->typeImage1->TabIndex = 5;
            this->typeImage1->TabStop = false;
            // 
            // typeImage2
            // 
            this->typeImage2->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->typeImage2->Location = System::Drawing::Point(392, 36);
            this->typeImage2->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->typeImage2->Name = L"typeImage2";
            this->typeImage2->Size = System::Drawing::Size(88, 29);
            this->typeImage2->TabIndex = 6;
            this->typeImage2->TabStop = false;
            // 
            // fireImage
            // 
            this->fireImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fireImage.BackgroundImage")));
            this->fireImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->fireImage->Location = System::Drawing::Point(103, 34);
            this->fireImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->fireImage->Name = L"fireImage";
            this->fireImage->Size = System::Drawing::Size(60, 21);
            this->fireImage->TabIndex = 7;
            this->fireImage->TabStop = false;
            // 
            // waterImage
            // 
            this->waterImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"waterImage.BackgroundImage")));
            this->waterImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->waterImage->Location = System::Drawing::Point(169, 34);
            this->waterImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->waterImage->Name = L"waterImage";
            this->waterImage->Size = System::Drawing::Size(60, 21);
            this->waterImage->TabIndex = 8;
            this->waterImage->TabStop = false;
            // 
            // electricImage
            // 
            this->electricImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"electricImage.BackgroundImage")));
            this->electricImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->electricImage->Location = System::Drawing::Point(235, 34);
            this->electricImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->electricImage->Name = L"electricImage";
            this->electricImage->Size = System::Drawing::Size(60, 21);
            this->electricImage->TabIndex = 9;
            this->electricImage->TabStop = false;
            // 
            // grassImage
            // 
            this->grassImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"grassImage.BackgroundImage")));
            this->grassImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->grassImage->Location = System::Drawing::Point(301, 34);
            this->grassImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->grassImage->Name = L"grassImage";
            this->grassImage->Size = System::Drawing::Size(60, 21);
            this->grassImage->TabIndex = 10;
            this->grassImage->TabStop = false;
            // 
            // iceImage
            // 
            this->iceImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"iceImage.BackgroundImage")));
            this->iceImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->iceImage->Location = System::Drawing::Point(367, 34);
            this->iceImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->iceImage->Name = L"iceImage";
            this->iceImage->Size = System::Drawing::Size(60, 21);
            this->iceImage->TabIndex = 11;
            this->iceImage->TabStop = false;
            // 
            // fightingImage
            // 
            this->fightingImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fightingImage.BackgroundImage")));
            this->fightingImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->fightingImage->Location = System::Drawing::Point(37, 80);
            this->fightingImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->fightingImage->Name = L"fightingImage";
            this->fightingImage->Size = System::Drawing::Size(60, 21);
            this->fightingImage->TabIndex = 12;
            this->fightingImage->TabStop = false;
            // 
            // poisonImage
            // 
            this->poisonImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"poisonImage.BackgroundImage")));
            this->poisonImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->poisonImage->Location = System::Drawing::Point(103, 80);
            this->poisonImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->poisonImage->Name = L"poisonImage";
            this->poisonImage->Size = System::Drawing::Size(60, 21);
            this->poisonImage->TabIndex = 13;
            this->poisonImage->TabStop = false;
            // 
            // groundImage
            // 
            this->groundImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"groundImage.BackgroundImage")));
            this->groundImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->groundImage->Location = System::Drawing::Point(169, 80);
            this->groundImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groundImage->Name = L"groundImage";
            this->groundImage->Size = System::Drawing::Size(60, 21);
            this->groundImage->TabIndex = 14;
            this->groundImage->TabStop = false;
            // 
            // flyingImage
            // 
            this->flyingImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"flyingImage.BackgroundImage")));
            this->flyingImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->flyingImage->Location = System::Drawing::Point(235, 80);
            this->flyingImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->flyingImage->Name = L"flyingImage";
            this->flyingImage->Size = System::Drawing::Size(60, 21);
            this->flyingImage->TabIndex = 15;
            this->flyingImage->TabStop = false;
            // 
            // psychicImage
            // 
            this->psychicImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"psychicImage.BackgroundImage")));
            this->psychicImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->psychicImage->Location = System::Drawing::Point(301, 80);
            this->psychicImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->psychicImage->Name = L"psychicImage";
            this->psychicImage->Size = System::Drawing::Size(60, 21);
            this->psychicImage->TabIndex = 16;
            this->psychicImage->TabStop = false;
            // 
            // bugImage
            // 
            this->bugImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"bugImage.BackgroundImage")));
            this->bugImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->bugImage->Location = System::Drawing::Point(367, 80);
            this->bugImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->bugImage->Name = L"bugImage";
            this->bugImage->Size = System::Drawing::Size(60, 21);
            this->bugImage->TabIndex = 17;
            this->bugImage->TabStop = false;
            // 
            // rockImage
            // 
            this->rockImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"rockImage.BackgroundImage")));
            this->rockImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->rockImage->Location = System::Drawing::Point(37, 130);
            this->rockImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->rockImage->Name = L"rockImage";
            this->rockImage->Size = System::Drawing::Size(60, 21);
            this->rockImage->TabIndex = 18;
            this->rockImage->TabStop = false;
            // 
            // ghostImage
            // 
            this->ghostImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"ghostImage.BackgroundImage")));
            this->ghostImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->ghostImage->Location = System::Drawing::Point(103, 130);
            this->ghostImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->ghostImage->Name = L"ghostImage";
            this->ghostImage->Size = System::Drawing::Size(60, 21);
            this->ghostImage->TabIndex = 19;
            this->ghostImage->TabStop = false;
            // 
            // dragonImage
            // 
            this->dragonImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"dragonImage.BackgroundImage")));
            this->dragonImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->dragonImage->Location = System::Drawing::Point(169, 130);
            this->dragonImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->dragonImage->Name = L"dragonImage";
            this->dragonImage->Size = System::Drawing::Size(60, 21);
            this->dragonImage->TabIndex = 20;
            this->dragonImage->TabStop = false;
            // 
            // darkImage
            // 
            this->darkImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"darkImage.BackgroundImage")));
            this->darkImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->darkImage->Location = System::Drawing::Point(235, 130);
            this->darkImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->darkImage->Name = L"darkImage";
            this->darkImage->Size = System::Drawing::Size(60, 21);
            this->darkImage->TabIndex = 21;
            this->darkImage->TabStop = false;
            // 
            // steelImage
            // 
            this->steelImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"steelImage.BackgroundImage")));
            this->steelImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->steelImage->Location = System::Drawing::Point(301, 130);
            this->steelImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->steelImage->Name = L"steelImage";
            this->steelImage->Size = System::Drawing::Size(60, 21);
            this->steelImage->TabIndex = 22;
            this->steelImage->TabStop = false;
            // 
            // fairyImage
            // 
            this->fairyImage->BackgroundImage = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"fairyImage.BackgroundImage")));
            this->fairyImage->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
            this->fairyImage->Location = System::Drawing::Point(367, 130);
            this->fairyImage->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->fairyImage->Name = L"fairyImage";
            this->fairyImage->Size = System::Drawing::Size(60, 21);
            this->fairyImage->TabIndex = 23;
            this->fairyImage->TabStop = false;
            // 
            // groupBox1
            // 
            this->groupBox1->Controls->Add(this->fairyLabel);
            this->groupBox1->Controls->Add(this->steelLabel);
            this->groupBox1->Controls->Add(this->darkLabel);
            this->groupBox1->Controls->Add(this->dragonLabel);
            this->groupBox1->Controls->Add(this->ghostLabel);
            this->groupBox1->Controls->Add(this->rockLabel);
            this->groupBox1->Controls->Add(this->bugLabel);
            this->groupBox1->Controls->Add(this->psychicLabel);
            this->groupBox1->Controls->Add(this->flyingLabel);
            this->groupBox1->Controls->Add(this->groundLabel);
            this->groupBox1->Controls->Add(this->poisonLabel);
            this->groupBox1->Controls->Add(this->fightingLabel);
            this->groupBox1->Controls->Add(this->iceLabel);
            this->groupBox1->Controls->Add(this->grassLabel);
            this->groupBox1->Controls->Add(this->electricLabel);
            this->groupBox1->Controls->Add(this->waterLabel);
            this->groupBox1->Controls->Add(this->normalLabel);
            this->groupBox1->Controls->Add(this->fireLabel);
            this->groupBox1->Controls->Add(this->bugImage);
            this->groupBox1->Controls->Add(this->fairyImage);
            this->groupBox1->Controls->Add(this->normalImage);
            this->groupBox1->Controls->Add(this->steelImage);
            this->groupBox1->Controls->Add(this->fireImage);
            this->groupBox1->Controls->Add(this->darkImage);
            this->groupBox1->Controls->Add(this->waterImage);
            this->groupBox1->Controls->Add(this->dragonImage);
            this->groupBox1->Controls->Add(this->electricImage);
            this->groupBox1->Controls->Add(this->ghostImage);
            this->groupBox1->Controls->Add(this->grassImage);
            this->groupBox1->Controls->Add(this->rockImage);
            this->groupBox1->Controls->Add(this->iceImage);
            this->groupBox1->Controls->Add(this->fightingImage);
            this->groupBox1->Controls->Add(this->psychicImage);
            this->groupBox1->Controls->Add(this->poisonImage);
            this->groupBox1->Controls->Add(this->flyingImage);
            this->groupBox1->Controls->Add(this->groundImage);
            this->groupBox1->Font = (gcnew System::Drawing::Font(L"Segoe UI", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->groupBox1->Location = System::Drawing::Point(36, 70);
            this->groupBox1->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Padding = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->groupBox1->Size = System::Drawing::Size(469, 209);
            this->groupBox1->TabIndex = 24;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Type Effectiveness";
            // 
            // fairyLabel
            // 
            this->fairyLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->fairyLabel->Location = System::Drawing::Point(378, 155);
            this->fairyLabel->Name = L"fairyLabel";
            this->fairyLabel->Size = System::Drawing::Size(40, 21);
            this->fairyLabel->TabIndex = 41;
            this->fairyLabel->Text = L"1";
            this->fairyLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // steelLabel
            // 
            this->steelLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->steelLabel->Location = System::Drawing::Point(310, 155);
            this->steelLabel->Name = L"steelLabel";
            this->steelLabel->Size = System::Drawing::Size(40, 21);
            this->steelLabel->TabIndex = 40;
            this->steelLabel->Text = L"1";
            this->steelLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // darkLabel
            // 
            this->darkLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->darkLabel->Location = System::Drawing::Point(246, 155);
            this->darkLabel->Name = L"darkLabel";
            this->darkLabel->Size = System::Drawing::Size(40, 21);
            this->darkLabel->TabIndex = 39;
            this->darkLabel->Text = L"1";
            this->darkLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // dragonLabel
            // 
            this->dragonLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->dragonLabel->Location = System::Drawing::Point(180, 155);
            this->dragonLabel->Name = L"dragonLabel";
            this->dragonLabel->Size = System::Drawing::Size(40, 21);
            this->dragonLabel->TabIndex = 38;
            this->dragonLabel->Text = L"1";
            this->dragonLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // ghostLabel
            // 
            this->ghostLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->ghostLabel->Location = System::Drawing::Point(114, 155);
            this->ghostLabel->Name = L"ghostLabel";
            this->ghostLabel->Size = System::Drawing::Size(40, 21);
            this->ghostLabel->TabIndex = 37;
            this->ghostLabel->Text = L"1";
            this->ghostLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // rockLabel
            // 
            this->rockLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->rockLabel->Location = System::Drawing::Point(48, 155);
            this->rockLabel->Name = L"rockLabel";
            this->rockLabel->Size = System::Drawing::Size(40, 21);
            this->rockLabel->TabIndex = 36;
            this->rockLabel->Text = L"1";
            this->rockLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // bugLabel
            // 
            this->bugLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->bugLabel->Location = System::Drawing::Point(378, 105);
            this->bugLabel->Name = L"bugLabel";
            this->bugLabel->Size = System::Drawing::Size(40, 21);
            this->bugLabel->TabIndex = 35;
            this->bugLabel->Text = L"1";
            this->bugLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // psychicLabel
            // 
            this->psychicLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->psychicLabel->Location = System::Drawing::Point(310, 105);
            this->psychicLabel->Name = L"psychicLabel";
            this->psychicLabel->Size = System::Drawing::Size(40, 21);
            this->psychicLabel->TabIndex = 34;
            this->psychicLabel->Text = L"1";
            this->psychicLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // flyingLabel
            // 
            this->flyingLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->flyingLabel->Location = System::Drawing::Point(246, 105);
            this->flyingLabel->Name = L"flyingLabel";
            this->flyingLabel->Size = System::Drawing::Size(40, 21);
            this->flyingLabel->TabIndex = 33;
            this->flyingLabel->Text = L"1";
            this->flyingLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // groundLabel
            // 
            this->groundLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->groundLabel->Location = System::Drawing::Point(180, 105);
            this->groundLabel->Name = L"groundLabel";
            this->groundLabel->Size = System::Drawing::Size(40, 21);
            this->groundLabel->TabIndex = 32;
            this->groundLabel->Text = L"1";
            this->groundLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // poisonLabel
            // 
            this->poisonLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->poisonLabel->Location = System::Drawing::Point(114, 105);
            this->poisonLabel->Name = L"poisonLabel";
            this->poisonLabel->Size = System::Drawing::Size(40, 21);
            this->poisonLabel->TabIndex = 31;
            this->poisonLabel->Text = L"1";
            this->poisonLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // fightingLabel
            // 
            this->fightingLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->fightingLabel->Location = System::Drawing::Point(48, 105);
            this->fightingLabel->Name = L"fightingLabel";
            this->fightingLabel->Size = System::Drawing::Size(40, 21);
            this->fightingLabel->TabIndex = 30;
            this->fightingLabel->Text = L"1";
            this->fightingLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // iceLabel
            // 
            this->iceLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->iceLabel->Location = System::Drawing::Point(378, 55);
            this->iceLabel->Name = L"iceLabel";
            this->iceLabel->Size = System::Drawing::Size(40, 21);
            this->iceLabel->TabIndex = 29;
            this->iceLabel->Text = L"1";
            this->iceLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // grassLabel
            // 
            this->grassLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->grassLabel->Location = System::Drawing::Point(312, 55);
            this->grassLabel->MaximumSize = System::Drawing::Size(40, 21);
            this->grassLabel->Name = L"grassLabel";
            this->grassLabel->Size = System::Drawing::Size(40, 21);
            this->grassLabel->TabIndex = 28;
            this->grassLabel->Text = L"1";
            this->grassLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // electricLabel
            // 
            this->electricLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->electricLabel->Location = System::Drawing::Point(246, 55);
            this->electricLabel->MaximumSize = System::Drawing::Size(40, 21);
            this->electricLabel->Name = L"electricLabel";
            this->electricLabel->Size = System::Drawing::Size(40, 21);
            this->electricLabel->TabIndex = 27;
            this->electricLabel->Text = L"1";
            this->electricLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // waterLabel
            // 
            this->waterLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->waterLabel->Location = System::Drawing::Point(180, 55);
            this->waterLabel->Name = L"waterLabel";
            this->waterLabel->Size = System::Drawing::Size(40, 21);
            this->waterLabel->TabIndex = 26;
            this->waterLabel->Text = L"1";
            this->waterLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // normalLabel
            // 
            this->normalLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->normalLabel->Location = System::Drawing::Point(48, 55);
            this->normalLabel->Name = L"normalLabel";
            this->normalLabel->Size = System::Drawing::Size(40, 21);
            this->normalLabel->TabIndex = 25;
            this->normalLabel->Text = L"1";
            this->normalLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // fireLabel
            // 
            this->fireLabel->Font = (gcnew System::Drawing::Font(L"Segoe UI", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
                static_cast<System::Byte>(0)));
            this->fireLabel->Location = System::Drawing::Point(114, 55);
            this->fireLabel->Name = L"fireLabel";
            this->fireLabel->Size = System::Drawing::Size(40, 21);
            this->fireLabel->TabIndex = 24;
            this->fireLabel->Text = L"1";
            this->fireLabel->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // MyForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(544, 327);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->typeImage2);
            this->Controls->Add(this->typeImage1);
            this->Controls->Add(this->pokemonNumberText);
            this->Controls->Add(this->pokemonNameText);
            this->Controls->Add(this->pokemonName);
            this->Controls->Add(this->pokemonNumber);
            this->Margin = System::Windows::Forms::Padding(3, 4, 3, 4);
            this->Name = L"MyForm";
            this->Text = L"MyForm";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->normalImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->typeImage1))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->typeImage2))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fireImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->waterImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->electricImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->grassImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->iceImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fightingImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->poisonImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->groundImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->flyingImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->psychicImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->bugImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->rockImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->ghostImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dragonImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->darkImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->steelImage))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->fairyImage))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->ResumeLayout(false);
            this->PerformLayout();

        }
#pragma endregion
    private: System::Void pokemonNumber_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
        PokemonData pokeData;
        std::string pokeNumber = msclr::interop::marshal_as<std::string>(pokemonNumber->SelectedItem->ToString());
        pokeData = pokemonDatabase.findPokemonByNumber(pokeNumber);

        //Setting the Pokemon name to the correct pokemon
        std::string pokeName = pokeData.basicAttributes[POKEMON_NAME];
        
        int index = pokemonName->FindString(gcnew String(pokeName.c_str()));
        pokemonName->SelectedIndex = index;

        //Setting the first type
        std::string pokeType = pokeData.basicAttributes[POKEMON_TYPE1];
        std::string imageString = "typeimg\\" + pokeType + ".png";
        String^ imageString1 = gcnew String(imageString.c_str());

        Image^ typeImg1 = Image::FromFile(imageString1);
        typeImage1->BackgroundImage = typeImg1;

        //Setting second type
        std::string pokeType2 = pokeData.basicAttributes[POKEMON_TYPE2];
        if (pokeType2 != "None") {
            imageString = "typeimg\\" + pokeType2 + ".png";
            imageString1 = gcnew String(imageString.c_str());
            typeImg1 = Image::FromFile(imageString1);
            typeImage2->BackgroundImage = typeImg1;
        }
        else {
            typeImage2->BackgroundImage = typeImage2->Image;
        }
        
        //Setting weaknesses
        float weakness[18];
        pokemonDatabase.getWeakness(weakness, pokeType, pokeType2);
        setPokemonWeakness(weakness);
    }

    private: System::Void pokemonName_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
        PokemonData pokeData;
        std::string pokeName = msclr::interop::marshal_as<std::string>(pokemonName->SelectedItem->ToString());
        pokeData = pokemonDatabase.findPokemonByName(pokeName);

        //Setting the Pokemon number to the correct number
        std::string pokeNumber = pokeData.basicAttributes[POKEMON_NUMBER];
        int index = pokemonNumber->FindString(gcnew String(pokeNumber.c_str()));
        pokemonNumber->SelectedIndex = index;

        //Setting the first type
        std::string pokeType = pokeData.basicAttributes[POKEMON_TYPE1];

        //Setting second type
        std::string pokeType2 = pokeData.basicAttributes[POKEMON_TYPE2];

        //Setting weaknesses
        float weakness[18];
        pokemonDatabase.getWeakness(weakness, pokeType, pokeType2);
        setPokemonWeakness(weakness);
    }
};
}
