# ProWorld
## 1. Introduction

Through the course of time, some stories have become interactive. This could have been happening since campfire tales, where the narrator would add suggestions to their performance. A story that is single-handedly dictated by one author is nothing new, but another more modern and barely explored option is a system-driven storytelling (like the “Choose Your Adventure” type of books). An even more modern example are video games, in which thanks to programming, plans for procedural systems seem to keep on moving forward. 
## 2. Creation 
### 2.1. App Set Up
The code utilizes an object called App that is managed in the main.cpp of the project. Throughout the execution App calls its methods in order with each one having its own purpose.

Constructor: In the App constructor, all the sub-objects are created and added to a list so that they can be executed in the desired order.
Start(): App sets up all the sub-objects so that when they are executed, they are ready to work properly. This can go from setting up a world, to retrieve any outside information that may be needed.
Update(): After everything is set up, the system starts running in a loop so the application does not finish the process. Update() handles all output that is being printed every frame, as well as all input from the user.
CleanUp(): When the application is turned off, CleanUp() is called. It handles each sub-object and prepares it before being destroyed. It also can be in charge of emptying out memory that cannot be freed during during its destructor method.
Destructor(): The destructor only frees the memory of the sub-objects created at the constructor.

Each sub-object in the application is called module. Each module has a different purpose:

File System: Manages loading XML files that contain data that is not in the project. These are mostly databases that are loaded through this module and are accessible from outside the project.
Concept Manager: This module is in charge of receiving all data from the File System module and load each set of words called concepts that will be used from inside the app. The concepts are organized in lists and it includes useful methods that maybe needed from other modules.
Name Generator: As self explanatory as it looks, it creates names for different things in the application such as names, last names or city names.
World: This module handles all the world creation as well as its characters through different algorithms or sets of values.
Narration: This module handles all data from the world and prepares it to be printed in a human-readable way.
Graphics: Lastly, in this module all narrative elements are printed to the user, it also interacts with possible input and manages all windows in the application.
Story: Ties the story together utilizing the generated data from other modules as well as the external databases in XML.

### 2.2 User Interface: Module Graphics

The user interface (UI) for this project is intended to be simplistic as the user does not have much input or interaction. However, in order to not use a console panel during execution, I decided to use a library called Dear ImGui and implement OpenGL 3. This library offers  a huge variety of options for developers and it counts with the support of huge companies such as Google or Blizzard.

The module updating the UI each frame is the Graphics Module, which handles the initialization of OpenGL in its constructor and sets up a window to use in its start method.
During each of its updates, the UI is refreshed. While this is not ideal since the text or displayed windows are not updated, it is good practice to have it set up like this for a couple of reasons: The first one is that if the code were to progress and include real time updates of the text, the code on the update() would have to be reorganized. The second one is that it makes it easier to restart the world without having to turn off the application.

There are a total of four windows in the application:
Main Menu: It has a title and a description of the application while also offering a short description of what it does and what to expect.
World: It shows some in depth information about the world such us important cities or locations. The user will read what important places are in the world according to where they’re placed in it, for example what is in the north or what is in the southeast. This allows a more visual support for the world since it does not have a map.
Characters: Here the user will get to know the main cast. Each character has a moral alignment, name, age, race, city of origin, a goal, a main flaw and lastly an archetype followed by a short description of how this archetype behaves. If the character is evil, the archetype is switched to its shadow version which is inherently more chaotic and vile.
Story: Directly displays the story.

### 2.3. FileSystem Module

The FileSystem module is in charge to communicate with external data files (XML). Generally, there are two markup languages useful for this sort of interaction, the other one being JSON. While both are human-readable and hierarchical, I chose XML because going into this project I did not know entirely foresee the scope of it. XML offers a lot more possibilities than JSON, however it is also more difficult to implement. In the end, I think JSON would have been a better choice overall as it is simpler.

The FileSystem module is the first one to be created and to call start(), this is because most of the other modules require the information that is loaded at the beginning of the application. Additionally, this module does not have an update - or more correctly, its update does nothing - since loading the XML files each frame would be a mistake.

There are many XML files, each with different information and different concept types. What is great about XML, is that I can change the information of a concept or add a new one for the code to use without having to update the solution each time nor having to browse through dozens of files.

### 2.4. FileSystem Module

The Concept Manager module stores all the information loaded from the FileSystem manager, creates every concept with its corresponding information and sorts it in different lists according to their type. Furthermore, the module contains useful methods for other modules, like returning a set of adjective concepts sorted by their priority or return all adjectives of the same priority to check that they do not repeat themselves.

### 2.5 Module: Name Generator

The character names have to be interesting but still intuitive to pronounce, for that I have used prefixes and suffixes that would sound somewhat familiar even if they come from different cultures. There are female and male names as well as eastern names (both chinese and japanese) and tropical names that sound slightly more exotic. Characters that identify as nonbinary have a name randomly sorted from female or male. There is a combination of 486 names for common males and 648 for common females. For eastern names and eastern culture the family surname is very important so it must be there. Chinese names are combination of a set of predefined names and surnames, with a total of 1260 names for chinese sounding male names and 1302 for females. Tropical names have the same approach, tropical (or rather exotic) sounding names give a total of 1.312 for male and 1.148 for females. Lastly, Japanese sounding names take a different approach which gives a very interesting result: A set of prefix syllables for the name, however the suffix is determined by the gender of the character. Also, the Japanese surname is conformed of a set of syllables combining with themselves. The surname can have a chance of having either one syllable or two, and the name can have up to two plus the syllable matching their gender. This means an astonishing number of over 46 million combinations of names for males alone.

### 2.6 ModuleWorld

This module handles the creation of the world and its characters. While creating the world, it must be procedural. How it does so has already been hinted previously, but here I will further explain how each part of the world interacts or inherits from another.

The world starts with a name given by the NameGenerator module and it is given a random climate loaded from the Concept Manager. There are four climates: tropical and arid (hot), continental (tempered) and polar (cold). After that, the sky is created. During the sky creation, a it gives the sky a certain visibility from non-visible to fully visible. This type of sky will determine if the sun, stars and moon are visible. After that, the daytime duration will be adjusted and if it is longer than the usual, the climate will be set to cold - similar to our planet. Lastly and for a fictional factor, there’s a chance that there are more than one sun (up to three) and more than one moon (up to six). Having more than one sun in orbit will change the climate of the world to either tropical or arid.

After the sky is set, the world is created. The world is divided in nine parts, the eight variants of the cardinal points plus the center (similar to a perfect square map/ a nine cells grid like Sudoku). In every world created there’s water, the amount of water is always between two and four cells and consequently, each earth cell colliding with a water cell becomes a coast cell.

There are twenty five locations in the world, these are spread randomly, although the first ones to be placed are where societies exist - cities, towns, villages and ports.
After each society has been placed, it’s turn for the rest of the locations (around 20 and 17).

To spawn the locations, a random cell is chosen and a location that suits that cell is placed. For example if the cell is full of water, a mountain will not spawn but an island or a reef could. Additionally, the locations must comply with that world’s climate, for example an ‘oasis’ concept can only exist under an ‘arid’ climate. 

The location database is rather long, if you want to check it you can go to the repository and search the XML file inside the Data folder. 

After every location has been placed, the societies need to come alive with some people living in them. For that, the race concepts have been created - which will include all information necessary to know if they can spawn. Each society is filled with a number of races depending on its size and the chosen races must comply with the society’s location in the world and climate.

Lastly, a name is given to each location. If the location is a society, the name will always be generated by the module Generator. However, that is not true for the rest of the locations. When a location is spawned, it has a chance of not having a name and a chance of having three types of different names.

When creating a location, a random number of available adjectives for that place are sent to the name generator. If the number of adjectives is zero, it has 50% chance of not having a name (i.e. mountain) or having a generated name (for example Highspear). If there are available adjectives for the location, then there’s a 33% or a ⅓ chances for each kind of name.
Generated name: This name is shared with the society name generator, that’s why they sound similar. In our world it is not rare to have places named like cities (like islands, mountains, bays, etc.)
‘The’ name: This kind of name adds a ‘the’ before the location name and puts a random adjective in the middle. For example: The Great Forest. Something interesting about this name, is that there are multiples of the same location in a zone, there’s a 50% chance that the placed is called The Many (location).
‘Color’ name: This kind of name is slightly similar to ‘The’ name, however only a handful of adjectives are available for this name and they are more mystic or abstract. This name does not have a ‘The’ before the name, so it usually goes something like: Black Sanctuary, Red River or Moon Temple.

To create the cast, the name is based in three values, the first one being its gender. If male or female, the character will have different names. If the character is transexual, they will have a name according to the gender they identify with, so trans-male or trans-female. If the character is non binary, the name is chosen at random between male or female. The second value that is taken in account is if the world is tropical or arid, in that case the societies have a chance to be of ‘tropical’ setting, which would give the characters an exotic name. Third and last, if the character comes from an eastern society the society has a chance to be ‘chinese’ like or ‘japanese’ like which would change the name of the character as well.

After the name and city of origin are given, the character will be from a race that lives in that city. The race is not only aesthetical, but it also determines which archetypes the characters will have. While the flaw is random from a pool of flaws, the goal of the character depends in their morals. Good and neutral characters will have hero goals, (such as ‘prove themselves’ or ‘become a hero’) and evil characters will have villain goals (such as ‘fear from losing social status’ or ‘destruction’). There are also goals that have no alignment (like ‘become rich’, or ‘escape from one’s fate’).

### 2.7: Module Story

To create the story, I decided to choose grammars (2.2.2.4). They are the most flexible generative method and it usually gives unexpected (surprising) results. As the procedural narrative approach, I chose a Simulation-Centric Approach. This helps the story to involve around the characters rather than a preset story, however I have to say that I used the famous hero’s journey as a template for the story development. I am unaware if this actually sits in the middle between Simulation-Centric (2.3.1) and Plot-Centric Approaches (2.3.2) but I think every story must have some sort of skeleton so I am guessing it leans more towards the Simulation-Centric Approach as it has all the characters with their own personality making choices.

In order to have the story working, I created a module called Module Story. In this module the story develops thanks to an Event Manager. This manager stores every kind of Event that could possibly happen in the story, and each Event compasses all information needed.

Each event has a set of rules that needs to be fulfilled as the story progresses as well as information on when they should happen. We could say that each event has:
Number of Characters Needed: For example two allied characters (hero and companion, maybe), or two enemy characters, or maybe even just one, or sometimes none.
The Information of Said Characters: For example a good character could maybe forgive the villain for their acts.
The Characters’ Stats: This is a loosely explanation of how it takes this into account, I will detail this later on.
The Part of the Story in which this event can happen, for example at the beginning o maybe at the end. This is represented with an id number that goes from 0 to 2.
The Order of Resolution: An event that would trigger a conflict would have a lower queue position than another that would end it. For example, starting a bar fight is a simple conflict trigger, and death is another one for conflict end. If the Resolution order is -1, it means that part of the story has finished, or if happens the end it would mean the story is over. This works similarly to “choose your path” story types.
The Action: This is the point of the event, this action is represented in a sentence or two explaining what happens. For example:
Actor(hero) “ and “ Actor(ally) “ decide to start a campfire in the middle of “ Location(forest1) “ to rest for the night.”
This would be a neutral event, where no big requirement needs to be fulfilled to happen (regardless of number of characters, their alignment and their archetypes). This means that this kind of event could be replaced by another neutral event such as:
Actor(hero) “ decides to spend the night at an inn near “ Location(city2) “.”
Visually, both sentences look different and will feel different for the user, but both are essentially the same event: Rest. This means that each event is not locked to having only one written output, but it could have many.
Bonus Information: A queued event (event coming after the current) may inquire for bonus information. For example, an event following the previous example:
Actor(hero) “ wakes up in the middle of the night to a noise, they see a “ GetRandomActor(location) “ in front of them.
GetRandomActor() gets a location and creates an actor for the story. If no location is sent to this event, the actor will be anything possible, for example a wizard. If a location is used, then the actor will be related to that location.
Event Type: The event helps the manager sort events in types, this helps the module story create better stories that do not repeat similar patterns. Including a type “Conflict Starts” to an event makes sure that there are not continuous conflicts if it can sort conflicts.

I have explained what an event contains, but the important part is the action. An action is a sentence or set of sentences that serve a purpose in the story. Creating an action starts with a sentence, for example:

When entering the cave, (Hero) heard some noises that induced fear in (hero pronoun).

This could be an example of a starting conflict event, or a hero’s downfall event. By editing the word cave with the previous location mentioned in a previous event, it could say instead ‘temple’ or ‘forest’.

When entering the location(), Hero() heard some noises that induced fear in hero->pronoun().

To add more flexibility in the event and avoid repetition, we make some adjustments so some words are chosen from a set of words. If we replaced ‘noises’ and ‘fear’ for other words, the outcome could vastly change.

When entering the temple, Alira heard some voices that induced courage in her.
When entering the castle, Erol heard some whispers that induced intranquility in him.

As we have both sentences, we see that the text gets somewhat flexible results. To make this even more interesting, we can add some adjectives.

When entering the Adjective(location()) location(), Hero() heard some Adjective(sound) sound() that induced feeling() in Hero->pronoun().


When entering the old mystical temple, Alira heard some weird voices that induced unsettlement in her.

When doing this, the sentence feels a lot more interesting and real. However, if three instances of this event appear in the text, the user will notice that it is a template. To fix this, we can change other parts in the text for other replacements that would change its structure.

When verb(location()) the location(), Hero() verb(sound) some Adjective(sound) sound() that verb(feeling()) feeling() in Hero->Pronoun(). 

If we fill each part of the event for example:

verb(location): approaching, inspecting, investigating, walking though
verb(sound): heard, listened, noticed.
adjective(sound): faint, loud, weird, intriguing, mysterious, distancing.
sound(): shatter, scream, screams, whispers, steps, noises
verb(feeling): induced, produced, caused.
feeling(): unsettlement, nervosity, anxiety, courage, interest, dread.

When approaching the jungle, Mabel noticed some distancing shatter that caused interest in her. 

Now we randomize the chance that adjectives spawn, not only that but we can also randomize the apparition of ‘When’ and ‘some’, and even cut short the sentence if we want. Placing semicolons, we can decide which parts can be deleted and we can even add some new parts. 

When verb(location()) the location(), Hero() verb(sound) ; some; Adjective(sound); place(); sound() place(); that verb(feeling()) feeling() in Hero->Pronoun(). 

place(): behind Hero->Pronoun(), far ahead, in the distance, above Hero->Pronoun().

Some results:
When inspecting the silent tomb, Anuk noticed some screams in the distance.
When walking through the jungle, Lara heard whispers that induced dread in her.
When investigating the ancient Temple of the Sun, Saldir heard faint voices behind him that produced anxiety in him. 

The ModuleStory connects the events and stores them in an event queue. This queue collects all events that happen in a story in order (story starts with event 0, and ends with event N). This module also has an algorithm to create a story that is not repetitive, that is done by checking the last event, and modifies the story statistics. These statistics are based on the amount of events of different types in the story, while also storing the type of the most recent events. That way, the story generator can decide what kind of event could go next. If there was not a sorter of any kind, the generator would be too random. Thanks to this sorter and the connexion of events through inquiring information, the story makes a lot more sense.

The personality of each character influences the events as well. If an event is of evil or chaotic nature, it must match the characters involved. However, this goes even further as many events require the characters to have certain archetypes, however characters with similar archetypes are not restricted to certain events. This means that, while yes, they can have special events just for them (for example a ‘Casanova’ or a ‘Seductress’ acquiring something they want by using the attraction of others or simply their beauty), they can also reach other events that may not be from their own archetype, or at least an unexpected route.

For characters to feel more unique and have their own routes, I implemented a set of statistics to each character (similarly of a character from a RPG). The stats are Strength, Dexterity, Intelligence and Charisma.

Each character has these stats secretly implemented as numbers, although the user can more or less know by reading the character’s description. These numbers go from 0 to 3, and measure how skilled a character is that stat. Zero would be not skilled, one would be somewhat skilled, two would be quite skilled, and three would be very skilled. A character has every stat set from 1 to 0 randomly, then when the character gets an archetype each stat is altered:
By adding from 1 to 2 to the skill.
By subtracting 1 to to the skill.
The skill can also not be affected.

When having to take decisions (decision events), the character would have to either: require a minimum skill of one or two stats for an event, or require a certain archetype for that event. An event is chosen at random from all events that fulfill one or the other while also complying with the alignment, that way the story progresses while each character stays loyal to their personality, attributes and alignment.

Lastly, there are also events for their flaws. Some flaws can alter an event like being scared of the dark while going through a cave, but the change is never too important or invasive of the story. There are events considering the goals as well, at the beginning of the story they can help the characters to ignite the action or they can make the end unfold in a different way.

### Constrictions 

By choosing a Simulation-Centric Approach, the engine faces problems that a regular narration would not face. At some points the story can feel lifeless or just plain weird or, the most common: unfocused. This is to be expected as in this type of choice acts like a simulation, which gives unforeseeable results. Some common errors that the stories have are:
Secondary characters not appearing enough, or not having a desired impact.
Secondary characters feeling pointless.
Villains’ purpose remains unclear.
The climax fails to tie each storyline together.
Villains working separately with different or unknown purposes.

These and others happen because the story is built around a main character and their journey.

During this project, I have used grammars in order to develop the story. This means that while every aspect in the world and its characters and their behaviour is interconnected, this cannot happen in the story itself. When developing the event system I realized that all events happening in the beginning could be accessed at the end by checking the queue, the problem was that an event cannot change itself to refer to a past event unless it is hardcoded to do so. With so many variations of events, hardcoding each event to contemplate many other variations of events was too difficult. When I tried to do it when I did not have many events coded, I also faced the problem that I had to store every single detail of each event to try to create some sort of plot twist, or reflexion of the past. I decided to take a liniar route and connect the events with the bonus info slot.

